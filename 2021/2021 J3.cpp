#include <iostream>
#include <string>
using namespace std;

int main() {
    string previousDirection = "";
    string direction;
    int steps;

    while (true) {
        string instruction;
        cin >> instruction;

        if (instruction == "99999") {
            break;
        }

        int firstDigit = instruction[0] - '0';
        int secondDigit = instruction[1] - '0';

        int sum = firstDigit + secondDigit;
        if (sum % 2 == 1) {
            direction = "left";
        } else if (sum % 2 == 0 && sum != 0) {
            direction = "right";
        } else {
            direction = previousDirection;
        }

        steps = stoi(instruction.substr(2));
        cout << direction << " " << steps << endl;

        previousDirection = direction;
    }

    return 0;
}