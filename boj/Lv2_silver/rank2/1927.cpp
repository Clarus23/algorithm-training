#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    priority_queue<int, vector<int>, greater<>> pq;
    int n; scanf("%d", &n);
    while(n--) {
        int x; scanf("%d", &x);

        if(x) { pq.push(x); continue; }
        if(pq.empty()) { printf("0\n"); continue; }

        printf("%d\n", pq.top()); pq.pop();
    }
    return 0;
}