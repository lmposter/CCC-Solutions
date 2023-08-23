#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1005;
int room[MAX][MAX];
bool visited[MAX][MAX];

int main() {
    int M, N;
    cin >> M >> N;

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> room[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int value = room[x][y];

        for (int i = 1; i * i <= value; ++i) {
            if (value % i == 0) {
                int a = i;
                int b = value / i;

                if (a <= M && b <= N && !visited[a][b]) {
                    q.push({a, b});
                    visited[a][b] = true;
                }

                if (a <= N && b <= M && !visited[b][a]) {
                    q.push({b, a});
                    visited[b][a] = true;
                }
            }
        }
    }

    if (visited[M][N]) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}