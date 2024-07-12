#include <iostream>

int main(void) {
    int n; scanf("%d", &n);
    int *tiling = new int[n+1];
    tiling[0] = 1; tiling[1] = 1;

    for(int i=2; i<=n; i++) tiling[i] = (tiling[i-1] + 2*tiling[i-2])%10007;
    printf("%d", tiling[n]);

    delete []tiling;
    return 0;
}