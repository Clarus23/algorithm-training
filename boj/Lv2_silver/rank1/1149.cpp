#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<tuple<int, int, int>> dp(n);
    scanf("%d %d %d", &get<0>(dp[0]), &get<1>(dp[0]), &get<2>(dp[0]));

    for(int i=1; i<n; i++) {
        int r, g, b; scanf("%d %d %d", &r, &g, &b);

        r += min(get<1>(dp[i-1]), get<2>(dp[i-1]));
        g += min(get<0>(dp[i-1]), get<2>(dp[i-1]));
        b += min(get<0>(dp[i-1]), get<1>(dp[i-1]));

        dp[i] = {r, g, b};
    }

    printf("%d", min({get<0>(dp[n-1]), get<1>(dp[n-1]), get<2>(dp[n-1])}));

    return 0;
}