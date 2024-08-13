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

    queue<pair<int, int>> q;
    vector<string> campus(n);
    for(int i=0; i<n; i++) {
        cin >> campus[i];

        if(campus[i].find('I') == string::npos) continue;
        q.push({i, campus[i].find('I')});
    }

    int cnt=0;
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for(pair<int, int> next : dirs) {
            next += cur;
            if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;
            if(campus[next.first][next.second] == 'X') continue;

            if(campus[next.first][next.second] == 'P') cnt++;
            campus[next.first][next.second] = 'X';
            q.push(next);
        }
    }

    if(cnt) cout << cnt;
    else cout << "TT";

    return 0;
}