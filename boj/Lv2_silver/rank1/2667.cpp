#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void operator+=(pair<int, int>& lv, const pair<int, int>& rv) {
    lv.first += rv.first;
    lv.second += rv.second;
}

int main(void) {
    pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n; cin >> n;
    vector<string> map(n);
    for(int i=0; i<n; i++) cin >> map[i];

    vector<int> apartment;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        if(map[i][j] == '0') continue;

        queue<pair<int, int>> q;
        q.push({i, j});
        map[i][j] = '0';
        apartment.push_back(1);
        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();

            for(pair<int, int> next : dirs) {
                next += cur;
                if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n) continue;
                if(map[next.first][next.second] == '0') continue;

                q.push(next);
                map[next.first][next.second] = '0';
                apartment.back()++;
            }
        }
    } sort(apartment.begin(), apartment.end());

    cout << apartment.size() << '\n';
    for(int i : apartment) cout << i << '\n';

    return 0;
}