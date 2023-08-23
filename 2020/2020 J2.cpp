#include <iostream>
using namespace std;

int main() {
    int P, N, R;
    cin >> P >> N >> R;

    int day = 0;
    int infected = N;
    int totalInfected = N;

    while (totalInfected <= P) {
        day++;
        infected *= R;
        totalInfected += infected;
    }

    cout << day << endl;

    return 0;
}