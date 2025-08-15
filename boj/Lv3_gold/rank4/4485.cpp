#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	풀이 아이디어 : dijkstra 최소 경로 탐색
		- 출발점과 도착점이 정해져있는 최단 경로 찾기.
		- 단, 가중치 그래프 라는 점에 주의
		- 일반적인 bfs로는 가중치 처리를 하기 힘듦. -> 완탐을 하게 됨.
		- 음의 가중치가 존재하지 않음. -> dijkstra algorithm
		
		- dijkstra를 이용해 최소 경로를 dynamic 하게 업데이트
		- 모든 탐색이 끝났을 때, 도착점의 dist는 최소 값.
		
	시간복잡도: O(N^2 * logN)
	
	메모리: 2276kb
	시간 : 4ms
*/

const int INF = 2e9;
const pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
	a.first += b.first;
	a.second += b.second;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int tc = 1;
	while(true) {
		int n; cin >> n;
		if(!n) break;
		
		vector<vector<int>> board(n, vector<int>(n));
		for(auto& row : board) for(int& square : row) cin >> square;
		
		vector<vector<int>> dist(n, vector<int>(n, INF));
		priority_queue<pair<int, pair<int, int>>> pq;
		
		// [n-1][n-1] 부터 출발 ~ [0][0]에 도착하게끔
		dist[n-1][n-1] = board[n-1][n-1];
		pq.push({-board[n-1][n-1], {n-1, n-1}});
		
		while(!pq.empty()) {
			int curDist = pq.top().first * -1;
			pair<int, int> cur = pq.top().second;
			pq.pop();
			
			if(curDist > dist[cur.first][cur.second]) continue;
			
			for(pair<int, int> next : dirs) {
				next += cur;
				if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n) continue;
				
				if(curDist + board[next.first][next.second] >= dist[next.first][next.second]) continue;
				
				dist[next.first][next.second] = curDist + board[next.first][next.second];
				pq.push({dist[next.first][next.second] * -1, next});
			}
		}
		
		cout << "Problem " << tc++ << ": " << dist[0][0] << "\n";
	}
	
	return 0;
}