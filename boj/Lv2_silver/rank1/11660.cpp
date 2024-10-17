#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> arr(n*n+1, 0);
    for(int i=1; i<=n*n; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i-1];
    }

    while(m--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int sum=0;
        for(int i=x1-1; i<x2; i++) {
            sum += (arr[i*n + y2] - arr[i*n + y1-1]);
        }
        printf("%d\n", sum);
    }

    return 0;
}