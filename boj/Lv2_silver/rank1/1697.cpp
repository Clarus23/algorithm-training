#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    bool isInvited[100001] = {false, };
    int n, k;
    scanf("%d %d", &n, &k);
    if(n == k) {
        printf("0");
        return 0;
    }

    queue<pair<int, int>> q;
    q.push({n, 0});
    isInvited[n] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int sec = q.front().second;
        q.pop();

        if(k == x-1 || k == x+1 || k == x*2) {
            printf("%d", sec+1);
            break;
        }

        if(x-1 >= 0 && !isInvited[x-1]) {
            q.push({x-1, sec+1});
            isInvited[x-1] = true;
        }
        if(x+1 < 100001 && !isInvited[x+1]) {
            q.push({x+1, sec+1});
            isInvited[x+1] = true;
        }
        if(x*2 < 100001 && !isInvited[x*2]) {
            q.push({x*2, sec+1});
            isInvited[x*2] = true;
        }
    }

    return 0;
}