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

    pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int n, m;
    cin >> n >> m;
    vector<vector<int>> paper(n, vector<int>(m));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> paper[i][j];

    int painting = 0;
    int maxSize = 0;

    for(int row=0; row<n; row++) {
        for(int col=0; col<m; col++) {
            if(paper[row][col] == 0) continue;

            painting++;
            int size = 1;

            queue<pair<int, int>> q;
            q.push({row, col});
            paper[row][col] = 0;
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                for(pair<int, int> next : dirs) {
                    next += cur;

                    if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;
                    if(paper[next.first][next.second] == 0) continue;

                    size++;
                    q.push(next);
                    paper[next.first][next.second] = 0;
                }
            }

            maxSize = (size > maxSize) ? size : maxSize;
        }
    }

    cout << painting << '\n' << maxSize;

    return 0;
}