#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<tuple<int, int, int>> cost(n);
    for(tuple<int, int, int>& rgb : cost) scanf("%d %d %d", &get<0>(rgb), &get<1>(rgb), &get<2>(rgb));

    vector<tuple<int, int, int>> dp(n);
    dp[0] = cost[0];

    for(int i=1; i<n; i++) {
        int r = get<0>(cost[i]) + min(get<1>(dp[i-1]), get<2>(dp[i-1]));
        int g = get<1>(cost[i]) + min(get<0>(dp[i-1]), get<2>(dp[i-1]));
        int b = get<2>(cost[i]) + min(get<0>(dp[i-1]), get<1>(dp[i-1]));

        dp[i] = {r, g, b};
    }

    printf("%d", min({get<0>(dp[n-1]), get<1>(dp[n-1]), get<2>(dp[n-1])}));

    return 0;
}