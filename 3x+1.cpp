#include <iostream>

using namespace std;

void recall(int x) {
	cout << x << " ";
	if (x != 1)
		if (x % 2 == 0)
			recall(x / 2);
		else
			recall(3 * x + 1);
}

int main() {
	int x;
	cin >> x;
	recall(x);
}