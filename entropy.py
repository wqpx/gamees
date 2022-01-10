import math

N = int(input("number of possible outcomes: "))
print("Please enter the probabilities in the form of", '\033[1m' + "a/b" + '\033[0m')

entropy = 0
prob_sum = 0

while True:
    for i in range(0, N):
        probability_str = input("insert probability of outcome " + str(i + 1) + ": ")
        probability = float(probability_str[0]) / float(probability_str[2:])
        while True:
            try:
                entropy += probability * math.log2(1 / probability)
            except ZeroDivisionError:
                print("You have entered the number 0")
                probability_str = input("Enter a valid number: ")
                probability = float(probability_str[0]) / float(probability_str[2:])
            except ValueError:
                print("You have entered a negative number")
                probability_str = input("Enter a valid number: ")
                probability = float(probability_str[0]) / float(probability_str[2:])
            else:
                break
        prob_sum += probability
    if prob_sum < 0.99 or prob_sum > 1.01:
        print("Sum of probabilities not equal to 1")
        print("Rerunning script...")
    else:
        break

print(entropy)
