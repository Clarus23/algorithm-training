#include <iostream>
#include <vector>
using namespace std;

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first+b.first, a.second+b.second};
}
void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // 짝수 +모양
    // 홀수 x모양
    pair<int, int> dirs[8] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

    int testCase; cin >> testCase;
    for(int t=1; t<=testCase; t++) {
        int max = 0;
        int n, m;
        cin >> n >> m;

        vector<vector<int>> board(n, vector<int>(n));
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> board[i][j];

        for(int row=0; row<n; row++) for(int col=0; col<n; col++) {
            int candidates[2] = {board[row][col], board[row][col]};

            for(int i=0; i<8; i++) {
                pair<int, int> cur = {row, col};
                for(int depth=1; depth<m; depth++) {
                    cur += dirs[i];

                    if(cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= n) break;

                    candidates[i%2] += board[cur.first][cur.second];
                }
            }

            for(int candidate : candidates)
                max = (max > candidate) ? max : candidate;
        }

        cout << '#' << t << ' ' << max << '\n';
    }

    return 0;
}