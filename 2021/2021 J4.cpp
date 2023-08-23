#include <iostream>
#include <vector>
using namespace std;

int main() {
    string input;
    cin >> input;

    vector<int> counts(3, 0);
    for (char c : input) {
        if (c == 'L') counts[0]++;
        else if (c == 'M') counts[1]++;
        else if (c == 'S') counts[2]++;
    }

    int swaps = 0;
    int currIdx = 0;

    for (int i = 0; i < counts[0]; ++i) {
        if (input[currIdx] != 'L') {
            while (input[currIdx] != 'L') {
                currIdx++;
            }
            swaps++;
        }
        currIdx++;
    }

    for (int i = 0; i < counts[1]; ++i) {
        if (input[currIdx] != 'M') {
            while (input[currIdx] != 'M') {
                currIdx++;
            }
            swaps++;
        }
        currIdx++;
    }

    cout << swaps << endl;

    return 0;
}