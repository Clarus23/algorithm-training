#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
	# [BOJ] G5 13549 숨바꼭질 3
	## 해법: 01BFS
	## 시간복잡도: O(N+K)
	## 메모리: 2,432 kb
	## 실행시간: 0 ms
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int dirs[3] = {0, -1, 1};
	int n, k;
	cin >> n >> k;
	
	vector<bool> isVisit(200000, false);
	
	deque<pair<int, int>> dq;
	dq.push_back({n, 0});
	while(!dq.empty()) {
		pair<int, int> cur = dq.front(); dq.pop_front();
		
		if(isVisit[cur.first]) continue;
		if(cur.first == k) {
			cout << cur.second;
			break;
		}
		
		isVisit[cur.first] = true;
		for(int& dir : dirs) {
			int nextPos = cur.first + (dir ? dir : cur.first);
			
			if(nextPos < 0 || nextPos >= 200000 || isVisit[nextPos]) continue;
			
			if(dir) dq.push_back({nextPos, cur.second+1});
			else dq.push_front({nextPos, cur.second});
		}
	}
}
