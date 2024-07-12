#include <iostream>

int main(void) {
    int n, m; scanf("%d %d", &n, &m);
    int *arr = new int[n+1];
    arr[0] = 0;
    for(int i=1; i<n+1; i++) {
        scanf("%d", arr+i);
        arr[i] += arr[i-1];
    }
    int a, b;
    while(m--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", arr[b]-arr[a-1]);
    }

    delete []arr;
    return 0;
}