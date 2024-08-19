#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return (abs(a) > abs(b) || (abs(a) == abs(b) && a > b));
    }
};

int main(void) {
    priority_queue<int, vector<int>, cmp> q;

    int n; scanf("%d", &n);
    while(n--) {
        int x; scanf("%d", &x);

        if(x) q.push(x);
        else {
            if(!q.empty()) {
                printf("%d\n", q.top()); q.pop();
            } else printf("0\n");
        }
    }

    return 0;
}