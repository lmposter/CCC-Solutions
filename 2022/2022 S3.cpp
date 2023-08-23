#include <iostream>
#include <vector>
using namespace std;

vector<int> piece;

bool isValidSample(const vector<int>& sample) {
    vector<bool> used(piece.size() + 1, false);
    for (int note : sample) {
        if (used[note]) {
            return false;
        }
        used[note] = true;
    }
    return true;
}

bool generatePiece(int N, int M, int K, int idx) {
    if (N == 0 && K == 0) {
        return true;
    }
    if (N <= 0 || K < 0 || idx > M) {
        return false;
    }

    for (int note = 1; note <= M; ++note) {
        piece.push_back(note);
        if (isValidSample(vector<int>(piece.end() - N, piece.end()))) {
            if (generatePiece(N - 1, M, K - isValidSample(vector<int>(piece.end() - N, piece.end())), idx + 1)) {
                return true;
            }
        }
        piece.pop_back();
    }

    return false;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    if (generatePiece(N, M, K, 1)) {
        for (int note : piece) {
            cout << note;
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}