#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    vector<bool> isVisited(100, false);
    vector<int> warp(100, 0);
    for(int i=0; i<n+m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        warp[x-1] = y-1;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    isVisited[0] = true;
    bool isEnd = false;
    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for(int i=6; i>0; i--) {
            int next = cur+i;

            if(next == 99) {
                printf("%d", cnt+1);
                isEnd = true;
                break;
            } if(next > 99) continue;

            if(isVisited[next]) continue;
            isVisited[next] = true;
            if(warp[next]) {
                next = warp[next];
                if(isVisited[next]) continue;
            }

            q.push({next, cnt+1});
        } if(isEnd) break;
    }

    return 0;
}