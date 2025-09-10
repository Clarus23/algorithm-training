#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c, n;
	cin >> c >> n;
	vector<int> dp(c+101, inf);
	dp[0] = 0;
	
	vector<pair<int, int>> cities(n);
	for(int i=0; i<n; ++i) {
		cin >> cities[i].first >> cities[i].second;
		dp[cities[i].second] = cities[i].first;
	}
	
	for(int i=1; i<=c+100; ++i) {
		int min = dp[i];
		for(pair<int, int> city : cities) {
			if(i < city.second) continue;
			
			int cand = dp[i-city.second] + city.first;
			min = (cand < min) ? cand : min;
		}
		
		dp[i] = min;
	}
	
	cout << *min_element(dp.begin()+c, dp.end());
	
	return 0;
}
