#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}

bool operator<(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first < b.first || (a.first == b.first && a.second < b.second));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    pair<int, int> shark;

    int n; cin >> n;
    vector<vector<int>> sea(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> sea[i][j];
            if(sea[i][j] == 9) {
                shark = {i, j};
                sea[i][j] = 0;
            }
        }
    }

    int timer = 0;
    int sharkSize = 2;
    int countOfEat = 0;
    while(true) {
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        visit[shark.first][shark.second] = true;

        int eatDepth = INF;
        pair<int, int> eatFish = {n, n};

        queue<pair<pair<int, int>, int>> q;
        q.push({shark, 0});
        while(!q.empty()) {
            pair<int, int> cur = q.front().first;
            int depth = q.front().second;
            q.pop();

            if(depth >= eatDepth) break;

            for(pair<int, int> next : dirs) {
                next += cur;

                if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n) continue;
                if(visit[next.first][next.second]) continue;
                if(sea[next.first][next.second] > sharkSize) continue;

                if(sea[next.first][next.second] == 0 || sea[next.first][next.second] == sharkSize) q.push({next, depth+1});
                else {
                    eatDepth = depth+1;
                    eatFish = (next < eatFish) ? next : eatFish;
                }

                visit[next.first][next.second] = true;
            }
        }

        if(eatDepth == INF) break;

        shark = eatFish;
        timer += eatDepth;
        sea[eatFish.first][eatFish.second] = 0;

        if(++countOfEat == sharkSize) {
            countOfEat = 0;
            sharkSize++;
        }
    }

    cout << timer;

    return 0;
}