#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n; scanf("%d", &n);
    int* dp = new int[n+1];

    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        dp[i] = i;
        for(int j=1; j*j<=i; j++) dp[i] = min(dp[i], 1+dp[i-j*j]);
    } printf("%d", dp[n]);

    delete []dp;
    return 0;
}