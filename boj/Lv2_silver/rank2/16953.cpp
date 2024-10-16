#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    int answer = -1;

    vector<bool> isVisited(b-a, false);
    queue<pair<long long, int>> q;
    q.push({a, 1});
    isVisited[0] = true;
    while(!q.empty()) {
        long long cur = q.front().first; int cnt = q.front().second; q.pop();

        if(cur*2 == b || cur*10+1 == b) {
            answer = cnt+1;
            break;
        }
        if(cur*2 < b && !isVisited[cur*2 - a]) {
            q.push({cur*2, cnt+1});
            isVisited[cur*2 - a] = true;
        }
        if(cur*10+1 < b && !isVisited[cur*10+1 - a]) {
            q.push({cur*10+1, cnt+1});
            isVisited[cur*10+1 - a] = true;
        }
    } printf("%d", answer);

    return 0;
}