#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;
    for (int fours = 0; fours <= N; fours += 4) {
        int fives = N - fours;
        if (fives % 5 == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}