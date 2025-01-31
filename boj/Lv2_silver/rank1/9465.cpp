#include <iostream>
#include <vector>
using namespace std;

void func(int dp[][3]) {
    for(int i=0; i<2; i++) {
        dp[0][i] = dp[0][i+1];
        dp[1][i] = dp[1][i+1];
    }
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        vector<vector<int>> sticker(2, vector<int>(n, 0));
        for(int i=0; i<2; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &sticker[i][j]);

        int dp[2][3] = {0, };
        for(int i=0; i<n; i++) {
            dp[0][2] = sticker[0][i] + max(dp[1][0], dp[1][1]);
            dp[1][2] = sticker[1][i] + max(dp[0][0], dp[0][1]);

            func(dp);
        }

        printf("%d\n", max(dp[0][2], dp[1][2]));
    }

    return 0;
}