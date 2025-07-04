#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}
bool operator==(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first == b.first && a.second == b.second);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int testCase; cin >> testCase;
    for(int t=1; t<=testCase; t++) {
        int n; cin >> n;
        vector<vector<int>> pool(n, vector<int>(n));
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> pool[i][j];

        pair<int, int> start;
        pair<int, int> goal;
        cin >> start.first >> start.second;
        cin >> goal.first >> goal.second;

        int time = -1;

        queue<pair<pair<int, int>, int>> q;
        q.push({start, 0});
        pool[start.first][start.second] = 1;
        while(!q.empty() && time == -1) {
            pair<int, int> cur = q.front().first;
            int curTime = q.front().second;
            q.pop();

            if(pool[cur.first][cur.second] == 3 && curTime%3 != 0) {
                q.push({cur, curTime+1});
                continue;
            }

            for(pair<int, int> next : dirs) {
                next += cur;

                if(next == goal) {
                    time = curTime+1;
                    break;
                }

                if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n) continue;
                if(pool[next.first][next.second] == 1 || pool[next.first][next.second] == 3) continue;

                q.push({next, curTime+1});
                pool[next.first][next.second] = (pool[next.first][next.second] == 0) ? 1 : 3;
            }
        }

        cout << '#' << t << ' ' << time << '\n';
    }

    return 0;
}