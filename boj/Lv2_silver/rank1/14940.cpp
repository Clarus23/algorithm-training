#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}

int main(void) {
    pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int n, m;
    scanf("%d %d", &n, &m);
    pair<int, int> start;
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<int>> result(n, vector<int>(m, -1));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        scanf("%d", &board[i][j]);
        if(board[i][j] == 2) start = {i, j};
        if(!board[i][j]) result[i][j] = 0;
    }

    queue<pair<int, int>> q;
    q.push(start);
    result[start.first][start.second] = 0;
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for(pair<int, int> next : dirs) {
            next += cur;
            if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;
            if(!board[next.first][next.second] || result[next.first][next.second] != -1) continue;

            q.push(next);
            result[next.first][next.second] = result[cur.first][cur.second]+1;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) printf("%d ", result[i][j]);
        puts("");
    }

    return 0;
}