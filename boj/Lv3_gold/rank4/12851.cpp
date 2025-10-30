#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	# [BOJ] G4 12851 숨바꼭질 2
	## 해법: BFS
	## 시간복잡도: O(N + K)
	## 메모리: 5,576 kb
	## 실행시간: 24ms
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int dirs[3] = {0, -1, 1};
	
	int n, k;
	cin >> n >> k;
	if(n == k) {
		cout << "0\n1";
		return 0;
	}
	
	vector<int> isVisit(200000, 2e9);
	
	int minTime = 2e9;
	int minCnt = 0;
	
	queue<pair<int, int>> q;
	q.push({n, 0});
	isVisit[n] = true;
	while(!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		
		for(int dir : dirs) {
			int nextPos = cur.first;
			
			if(!dir) nextPos *= 2;
			else nextPos += dir;
			
			if(nextPos < 0 || nextPos >= 200000 || isVisit[nextPos] < cur.second+1) continue;
			if(nextPos == k) {
				if(minTime > cur.second+1) {
					minTime = cur.second+1;
					minCnt = 1;
				} else if(minTime == cur.second+1) ++minCnt;
				
				continue;
			}
			
			q.push({nextPos, cur.second+1});
			isVisit[nextPos] = cur.second+1;
		}
	}
	
	cout << minTime << "\n" << minCnt;
}
