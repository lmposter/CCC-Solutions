#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, string> bids;

    for (int i = 0; i < N; ++i) {
        string name;
        int amount;
        cin >> name >> amount;

        if (bids.find(amount) == bids.end()) {
            bids[amount] = name;
        }
    }

    int highestBid = 0;
    string winner;

    for (auto it : bids) {
        if (it.first > highestBid) {
            highestBid = it.first;
            winner = it.second;
        }
    }

    cout << winner << endl;

    return 0;
}