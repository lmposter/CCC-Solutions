#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<char>> canvas(M, vector<char>(N, 'B'));

    for (int i = 0; i < K; ++i) {
        char choice;
        int index;
        cin >> choice >> index;

        if (choice == 'R') {
            for (int j = 0; j < N; ++j) {
                canvas[index - 1][j] = (canvas[index - 1][j] == 'B') ? 'G' : 'B';
            }
        } else if (choice == 'C') {
            for (int j = 0; j < M; ++j) {
                canvas[j][index - 1] = (canvas[j][index - 1] == 'B') ? 'G' : 'B';
            }
        }
    }

    int goldCount = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (canvas[i][j] == 'G') {
                goldCount++;
            }
        }
    }

    cout << goldCount << endl;

    return 0;
}
