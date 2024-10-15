#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n; scanf("%d", &n);
    vector<int> arr(n, 0);
    vector<int> dp(n, 0);

    int answer = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);

        int maxDp=0;
        for(int j=0; j<i; j++) {
            if(arr[j] >= arr[i]) continue;
            maxDp = (dp[j] > maxDp) ? dp[j] : maxDp;
        } dp[i] = maxDp+1;
        answer = (dp[i] > answer) ? dp[i] : answer;
    }

    printf("%d", answer);

    return 0;
}