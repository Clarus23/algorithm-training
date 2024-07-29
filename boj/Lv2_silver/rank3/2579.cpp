#include <iostream>
using namespace std;

int main(void) {
    int n; scanf("%d", &n);
    int* stairs = new int[n+1];
    stairs[0] = 0;
    for(int i=1; i<=n; i++) scanf("%d", stairs+i);

    int* dp = new int[n+1];
    dp[0] = 0;
    dp[1] = stairs[1];
    if(n != 1) dp[2] = stairs[1] + stairs[2];
    for(int i=3; i<=n; i++) {
        int case1 = dp[i-3] + stairs[i-1] + stairs[i];
        int case2 = dp[i-2] + stairs[i];

        dp[i] = (case1 > case2) ? case1 : case2;
    } printf("%d", dp[n]);

    delete []stairs;
    delete []dp;
    return 0;
}