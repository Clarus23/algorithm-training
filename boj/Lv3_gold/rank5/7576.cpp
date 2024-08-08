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
    scanf("%d %d", &m, &n);
    vector<vector<int>> box(n, vector<int>(m, 0));
    int unripeNum=0;
    queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &box[i][j]);
            if(box[i][j] == 1) q.push({{i, j}, 0});
            else if(!box[i][j]) unripeNum++;
        }
    }

    if(!unripeNum) {
        printf("0");
        return 0;
    }

    int day;
    while(!q.empty()) {
        pair<int, int> cur = q.front().first;
        day = q.front().second;
        q.pop();

        for(pair<int, int> next : dirs) {
            next += cur;
            if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;
            if(box[next.first][next.second]) continue;

            unripeNum--;
            box[next.first][next.second] = 1;
            q.push({next, day+1});
        }
    }

    if(unripeNum) printf("-1");
    else printf("%d", day);

    return 0;
}