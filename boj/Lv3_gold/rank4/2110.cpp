#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	# [BOJ] G4 2110 공유기 설치
	## 시간복잡도: O(N*logN)
		- sort: O(N*logN)
		- binary search(logM) + 내부 거리 확인(N): O(N*logM)
		- M은 N보다 작은게 보장되므로 총 시간복잡도는 O(N*logN)
	## 메모리: 2,804 kb
	## 실행시간: 36 ms
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, c;
	cin >> n >> c;
	
	vector<int> homes(n);
	for(int& home : homes) cin >> home;
	sort(homes.begin(), homes.end());
	
	int ans = 0;
	int min = 1;
	int max = homes[n-1] - homes[0] + 1;
	while(min < max) {
		int mid = (min + max)/2;
		
		int setting = 1;
		int prev = 0;
		for(int i=1; (i<n && setting<c); ++i) {
			if(homes[i] - homes[prev] < mid) continue;
			
			++setting;
			prev = i;
		}
		
		if(setting >= c) {
			ans = (mid > ans ? mid : ans);
			min = mid+1;
		} else max = mid;
	}
	
	cout << ans;
	
	return 0;
}
