#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> house(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> house[i][j];

    map<char, vector<vector<int>>> dp;
    dp.insert({'h', vector<vector<int>>(n, vector<int>(n, 0))});
    dp.insert({'v', vector<vector<int>>(n, vector<int>(n, 0))});
    dp.insert({'d', vector<vector<int>>(n, vector<int>(n, 0))});

    for(int i=1; i<n; i++) {
        if(house[0][i]) break;
        dp['h'][0][i] = 1;
    }

    for(int i=1; i<n; i++) for(int j=1; j<n; j++) {
            if(house[i][j]) continue;
            dp['h'][i][j] += dp['h'][i][j-1] + dp['d'][i][j-1];
            dp['v'][i][j] += dp['v'][i-1][j] + dp['d'][i-1][j];

            if(house[i-1][j] || house[i][j-1]) continue;
            dp['d'][i][j] += dp['h'][i-1][j-1] + dp['v'][i-1][j-1] + dp['d'][i-1][j-1];
        }

    cout << dp['h'][n-1][n-1] + dp['v'][n-1][n-1] + dp['d'][n-1][n-1];

    return 0;
}