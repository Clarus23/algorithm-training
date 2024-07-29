#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}

int main(void) {
    pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int t; scanf("%d", &t);
    while(t--) {
        int m, n, k;
        scanf("%d %d %d", &m, &n, &k);
        vector<vector<bool>> field(n, vector<bool>(m, false));
        while(k--) {
            int x, y;
            scanf("%d %d", &x, &y);
            field[y][x] = true;
        } if(k == 1) {
            printf("1\n");
            continue;
        }

        int cnt=0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
            if(!field[i][j]) continue;

            cnt++;
            q.push({i, j});
            field[i][j] = false;
            while(!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();

                for(pair<int, int> dir : dirs) {
                    dir += cur;
                    if(dir.first<0 || dir.first>=n || dir.second<0 || dir.second>=m) continue;
                    if(!field[dir.first][dir.second]) continue;

                    q.push({dir.first, dir.second});
                    field[dir.first][dir.second] = false;
                }
            }
        } printf("%d\n", cnt);
    }
}