#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int x; scanf("%d", &x);
    if(x == 1) {
        printf("0");
        return 0;
    }

    queue<pair<int, int>> q;
    q.push({x, 0});
    pair<int, int> cur;
    while(true) {
        cur = q.front(); q.pop();
        if(cur.first == 2 || cur.first == 3) {
            printf("%d", cur.second+1);
            break;
        }

        if(!(cur.first%3)) q.push({cur.first/3, cur.second+1});
        if(!(cur.first%2)) q.push({cur.first/2, cur.second+1});
        q.push({cur.first-1, cur.second+1});
    }

    return 0;
}