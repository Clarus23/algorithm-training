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
    cin >> n >> m;
    vector<string> maze(n);
    for(int i=0; i<n; i++) cin >> maze[i];

    int cnt;
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    while(!q.empty()) {
        pair<int, int> cur = q.front().first;
        cnt = q.front().second; q.pop();

        if(cur.first == n-1 && cur.second == m-1) break;

        for(pair<int, int> next : dirs) {
            next += cur;
            if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;
            if(maze[next.first][next.second] == '0') continue;

            maze[next.first][next.second] = '0';
            q.push({next, cnt+1});
        }
    } cout << cnt;

    return 0;
}