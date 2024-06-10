#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n*m, 0);
    for(int i=0; i<n*m; i++) cin >> arr[i];
    vector<bool> flag(n*m, false);
    for(int i=0; i<k; i++) flag[i] = true;

    const int lrud[4] = {-1, 1, -m, m};

    int maxValue = INT_MIN;
    do {
        int cur=0;
        bool isCanceled = false;
        vector<int> banId;

        for(int i=0; i<m*n; i++) {
            if(flag[i]) {
                if(find(banId.begin(), banId.end(), i) != banId.end()) {
                    isCanceled = true;
                    break;
                }

                int row = i/m; int col = i%m;
                bool islrud[4] = {col!=0, col!=(m-1), row!=0, row!=(n-1)};
                for(int j=0; j<4; j++) if(islrud[j]) banId.push_back(i+lrud[j]);

                cur += arr[i];
            }
        } if(isCanceled) continue;

        maxValue = max(maxValue, cur);
    } while(prev_permutation(flag.begin(), flag.end()));

    cout << maxValue;

    return 0;
}