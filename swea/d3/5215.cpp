#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 풀이 아이디어
 * dynamic programming
 * dp[i] : 현재 재료까지, i 칼로리를 넘지 않는 최대의 만족도
 * dp[i] 의 두 가지 경우
 *  -> 현재 재료를 집어 넣는다 : dp[i-food.second] + food.first
 *  -> 현재 재료를 넣지 않는다 : dp[i]
 *
 * => dp[l] (l 칼로리에서의 최대 만족도)
 *
 * 시간 복잡도: O(NL)
 *
 * 난이도: 중상
 */
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		int n, l;
		cin >> n >> l;

		// 음식의 만족도(first)와 칼로리(second)
		vector<pair<int, int>> foods(n);
		for (auto& food : foods) cin >> food.first >> food.second;

		// dp 배열
		vector<int> dp(l+1, 0);
		for (const auto& food : foods) {
			for (int i = l; i >= 0; --i) {
				if (i < food.second) break;

				dp[i] = max(dp[i], food.first + dp[i - food.second]);
			}
		}

		cout << "#" << tc << " " << dp[l] << "\n";
	}

	return 0;
}