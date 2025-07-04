#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const pair<int, int> dirs[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int testCase; cin >> testCase;
    for(int t=1; t<=testCase; t++) {
        int n; cin >> n;
        vector<vector<int>> board(n, vector<int>(n, 0));

        int remain = n*n;
        for(int row=0; row<n; row++) {
            string s; cin >> s;
            for(int col=0; col<n; col++) {
                if(s[col] == '.') continue;

                remain--;
                board[row][col] = -1;
                for(pair<int, int> fringe : dirs) {
                    fringe += {row, col};

                    if(fringe.first < 0 || fringe.first >= n || fringe.second < 0 || fringe.second >= n) continue;
                    if(board[fringe.first][fringe.second] == -1) continue;

                    board[fringe.first][fringe.second]++;
                }
            }
        }

        int click = 0;
        for(int row=0; row<n; row++) for(int col=0; col<n; col++) {
            if(board[row][col] != 0) continue;
            
            click++;
            int area = 1;
            queue<pair<int, int>> q;
            q.push({row, col});
            board[row][col] = -1;
            while(!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();

                for(pair<int, int> fringe : dirs) {
                    fringe += cur;
                    if(fringe.first < 0 || fringe.first >= n || fringe.second < 0 || fringe.second >= n) continue;
                    if(board[fringe.first][fringe.second] == -1) continue;

                    if(board[fringe.first][fringe.second] == 0) q.push(fringe);

                    area++;
                    board[fringe.first][fringe.second] = -1;
                }
            }

            remain -= area;
        }

        cout << '#' << t << ' ' << click+remain << '\n';
    }

    return 0;
}