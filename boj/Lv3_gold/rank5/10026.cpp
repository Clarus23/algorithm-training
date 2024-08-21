#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void operator+=(pair<int, int>& lv, const pair<int, int>& rv) {
    lv.first += rv.first;
    lv.second += rv.second;
}

int main() {
    pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n; cin >> n;
    vector<string> paint(n);
    for(int i=0; i<n; i++) cin >> paint[i];

    int normal = 0, colorBlind = 0;
    queue<pair<int, int>> q;
    vector<string> temp(paint);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        if(temp[i][j] == 'G') paint[i][j] = 'R';
        if(temp[i][j] == ' ') continue;

        char target = temp[i][j];
        temp[i][j] = ' ';
        q.push({i, j});
        normal++;
        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();

            for(pair<int, int> next : dirs) {
                next += cur;
                if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n) continue;
                if(temp[next.first][next.second] != target) continue;

                if(target == 'G') paint[next.first][next.second] = 'R';
                temp[next.first][next.second] = ' ';
                q.push(next);
            }
        }
    }

    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        if(paint[i][j] == ' ') continue;

        char target = paint[i][j];
        paint[i][j] = ' ';
        q.push({i, j});
        colorBlind++;
        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();

            for(pair<int, int> next : dirs) {
                next += cur;
                if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n) continue;
                if(paint[next.first][next.second] != target) continue;

                paint[next.first][next.second] = ' ';
                q.push(next);
            }
        }
    }

    cout << normal << ' ' << colorBlind;

    return 0;
}