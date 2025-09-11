#include <iostream>
#include <vector>
using namespace std;

/*
 * # 풀이 아이디어: DP
 * 	- dp[i][j] => i부터 j까지의 행렬곱의 최소 cost.
 *	- dp[from][to] = min(All dp[from][k] + dp[k][to] + (from ~ k 와 k ~ to 의 행렬곱 cost)) (단, from <= k < to)
 * 
 * # 시간복잡도: O(N^3)
 * 
 * # 메모리: 3,084 kb
 * # 실행시간: 32 ms
 * # 체감난이도: 중상
 */

const int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	if(n == 1) { cout << 0; return 0; }
	
	vector<pair<int, int>> matrix(n);
	for(pair<int, int>& cur : matrix) cin >> cur.first >> cur.second;
	
	vector<vector<int>> dp(n, vector<int>(n));
	for(int len = 2; len<=n; ++len) {
		for(int from = 0; from<=n-len; ++from) {
			int to = from + len - 1;
			dp[from][to] = inf;
			
			for(int k=from; k<to; ++k) {
				int cost = dp[from][k] + dp[k+1][to] + matrix[from].first * matrix[k].second * matrix[to].second;
				dp[from][to] = (cost < dp[from][to]) ? cost : dp[from][to];
			}
		}
	}
	
	cout << dp[0][n-1];
	
	return 0;
}
