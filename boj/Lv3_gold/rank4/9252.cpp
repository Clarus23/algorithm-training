#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	string s1, s2;
	cin >> s1 >> s2;
	
	int n = s1.length();
	int m = s2.length();
	
	vector<vector<int>> dp(n+1, vector<int>(m+1));
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
		}
	}
	
	int size = dp[n][m];
	int top = size-1;
	vector<char> lcs(size);
	int row = n, col = m;
	while(top >= 0) {
		if(dp[row][col] == dp[row-1][col]) --row;
		else if(dp[row][col] == dp[row][col-1]) --col;
		else {
			--row; --col;
			lcs[top--] = s1[row];
		}
	}
	
	cout << size << "\n";
	for(char c : lcs) cout << c;
	
	return 0;
}