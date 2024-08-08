#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}
void operator+=(pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    a.first += b.first;
    a.second += b.second;
}

int main(void) {
    pair<int, pair<int, int>> dirs[6] = {{1, {0, 0}}, {-1, {0, 0}}, {0, {1, 0}}, {0, {-1, 0}}, {0, {0, 1}}, {0, {0, -1}}};
    int m, n, h;
    scanf("%d %d %d", &m, &n, &h);
    int unripeNum=0;
    vector<vector<vector<int>>> boxes(h, vector<vector<int>>(n, vector<int>(m, 0)));
    queue<pair<pair<int, pair<int, int>>, int>> q;
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                scanf("%d", &boxes[i][j][k]);
                if(boxes[i][j][k] == 1) q.push({{i, {j, k}}, 0});
                else if(!boxes[i][j][k]) unripeNum++;
            }
        }
    }

    if(!unripeNum) {
        printf("0");
        return 0;
    }

    int day;
    while(!q.empty()) {
        pair<int, pair<int, int>> cur = q.front().first;
        day = q.front().second; q.pop();

        for(pair<int, pair<int, int>> next : dirs) {
            next += cur;
            if(next.first < 0 || next.first >= h
             || next.second.first < 0 || next.second.first >= n
             || next.second.second < 0 || next.second.second >= m) continue;
            if(boxes[next.first][next.second.first][next.second.second]) continue;

            unripeNum--;
            boxes[next.first][next.second.first][next.second.second] = 1;
            q.push({next, day+1});
        }
    }

    if(unripeNum) printf("-1");
    else printf("%d", day);

    return 0;
}