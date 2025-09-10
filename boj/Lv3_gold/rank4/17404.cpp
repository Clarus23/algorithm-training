#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * # 풀이 아이디어: DP
 * 	- 마지막 집에서 시작 집의 색을 알아야 하니, 시작 집의 색깔에 맞춰 dp 테이블을 생성
 * 
 * # 시간복잡도: O(N)
 * 
 * # 메모리: 2,296 kb
 * # 실행시간: 0 ms
 * # 체감난이도: 중하
 */

const int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	// 첫번째 값 -> 시작집 color 가 0, 1, 2
	// 두번째 값 -> 현재 집의 번호
	// 세번째 값 -> 현재 집 color 가 0, 1, 2
	vector<vector<vector<int>>> dp(3, vector<vector<int>>(n, vector<int>(3, 0)));
	
	int r, g, b;
	// 0번 집
	cin >> r >> g >> b;
	dp[0][0][0] = r;
	dp[1][0][1] = g;
	dp[2][0][2] = b;
	dp[0][0][1] = dp[0][0][2] = dp[1][0][0] = dp[1][0][2] = dp[2][0][0] = dp[2][0][1] = inf;
	
	for(int i=1; i<n; ++i) {
		cin >> r >> g >> b;
		for(int start=0; start<3; ++start) {
			dp[start][i][0] = r + min(dp[start][i-1][1], dp[start][i-1][2]);
			dp[start][i][1] = g + min(dp[start][i-1][0], dp[start][i-1][2]);
			dp[start][i][2] = b + min(dp[start][i-1][0], dp[start][i-1][1]);
		}
	}

	int minCost = inf;
	for(int start=0; start<3; ++start) {
		for(int color=0; color<3; ++color) {
			if(start == color) continue;
			minCost = (dp[start][n-1][color] < minCost) ? dp[start][n-1][color] : minCost;
		}
	}
	
	cout << minCost;
	
	return 0;
}
