#include <iostream>
#include <cmath>

using namespace std;

//this function finds the century doomsday and returns a number corresponding with a day of the week,
//the enumerating system begins with sunday as 0 and goes to saturday as 6
int doomsDayCentury(int century) {
	if (century < 18)
		while (century < 18)
			century += 4;
	if (century > 21)
		while (century > 21)
			century -= 4;
	switch (century) {
	case 18:
		return 5;
	case 19:
		return 3;
	case 20:
		return 2;
	case 21:
		return 0;
	default:
		return -1;
	}
}

// this function gets the argument to a number between and including 0 and 6
void reducingToActuallity(int& yearDoomsday) {
	if (yearDoomsday > 0)
		while (yearDoomsday > 6)
			yearDoomsday -= 7;
	else if (yearDoomsday < 0)
		while (yearDoomsday < -6)
			yearDoomsday += 7;
}

void bringingToActuallity(int& diff) {
	if (diff < 0)
		diff += 7;
}

int main() {

	struct date {
		int day, month, year;
	} givenDate;

	//this block gets the input
	cout << "Input the day: ";		cin >> givenDate.day;
	cout << "Input the month: ";	cin >> givenDate.month;
	cout << "Input the year: ";		cin >> givenDate.year;

	//this block finds the year doomsday
	int centuryDoomsday = doomsDayCentury(givenDate.year / 100);
	int yearDoomsday = centuryDoomsday + givenDate.year % 100 / 12 + givenDate.year % 100 % 12 + givenDate.year % 100 % 12 / 4;
	reducingToActuallity(yearDoomsday);

	int diff = 0;
	int v[13] = {0, 31, 28, 14, 4, 9, 6, 11, 8, 5, 10, 7, 12 };
	for (int i = 1; i <= 12; i++)
		if (givenDate.month == i) {
			diff = givenDate.day - v[i];
			diff += yearDoomsday;
			reducingToActuallity(diff);
			bringingToActuallity(diff);
			break;
		}
	switch (diff) {
	case 0:
		cout << "Sunday";
		break;
	case 1:
		cout << "Monday";
		break;
	case 2:
		cout << "Tuesday";
		break;
	case 3:
		cout << "Wednesday";
		break;
	case 4:
		cout << "Thursday";
		break;
	case 5:
		cout << "Friday";
		break;
	case 6:
		cout << "Saturday";
		break;
	default:
		cout << "Mil yey ay";
		break;
	}
}