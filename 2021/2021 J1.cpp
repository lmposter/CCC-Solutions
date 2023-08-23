#include <iostream>
using namespace std;

int main() {
    int B;
    cin >> B;

    int P = 5 * B - 400;
    int seaLevel = 0;

    if (P < 100) {
        seaLevel = 1;
    } else if (P > 100) {
        seaLevel = -1;
    }

    cout << P << endl;
    cout << seaLevel << endl;

    return 0;
}