#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* [BOJ] S2 2512 예산
* 풀이 아이디어: Binary Search
* 메모리: 2,184 kb
* 시간: 0 ms
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<int> costs(n, 0);
	for(int& cost : costs) cin >> cost;
	sort(costs.begin(), costs.end());
	
	vector<int> sum(n, 0);
	sum[0] = costs[0];
	for(int i=1; i<n; ++i) sum[i] = sum[i-1] + costs[i];
	
	int m; cin >> m;
	
	if(sum[n-1] <= m) {
		cout << costs[n-1];
		return 0;
	}
	
	int ans = 0;
	int min = 0;
	int max = costs[n-1]+1;
	while(min < max) {
		int cur = (min+max)/2;
		
		int idx = upper_bound(costs.begin(), costs.end(), cur) - costs.begin();
		
		int cost = sum[idx-1] + cur*(n - idx);
		
		
		if(cost > m) max = cur;
		else {
			min = cur+1;
			ans = cur;
		}
	}
	
	cout << ans;
	return 0;
}	
