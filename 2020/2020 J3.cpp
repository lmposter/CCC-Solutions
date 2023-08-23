#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> drops(N);

    for (int i = 0; i < N; i++) {
        char comma;
        cin >> drops[i].first >> comma >> drops[i].second;
    }

    int minX = drops[0].first, minY = drops[0].second;
    int maxX = drops[0].first, maxY = drops[0].second;

    for (int i = 1; i < N; i++) {
        minX = min(minX, drops[i].first);
        minY = min(minY, drops[i].second);
        maxX = max(maxX, drops[i].first);
        maxY = max(maxY, drops[i].second);
    }

    cout << minX - 1 << "," << minY - 1 << endl;
    cout << maxX + 1 << "," << maxY + 1 << endl;

    return 0;
}