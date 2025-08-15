#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	풀이 아이디어 : dijkstra 최단 경로 탐색
		- 음의 값이 존재하지 않는 가중치 그래프에서의 최단경로 탐색
		- dijkstra algorithm을 쓰겠구나
		- dijkstra를 사용하기 위해서는 최단 거리를 뽑아내는 자료구조가 필요하다
		- priority_queue를 이용한 최소힙 자료구조를 사용한다.
		
	시간복잡도: O(N^2 * logN)
	
	메모리: 6140kb
	실행시간: 47ms
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
	
	int t; cin >> t;
	for(int tc=1; tc<=t; ++tc) {
		int n; cin >> n;
		
		vector<vector<int>> board(n, vector<int>(n));
		for(auto& row : board) {
			string temp; cin >> temp;
			
			for(int i=0; i<n; ++i) {
				row[i] = temp[i] - '0';
			}
		}
		
		priority_queue<pair<int, pair<int, int>>> pq;
		vector<vector<int>> dist(n, vector<int>(n, INF));
		dist[n-1][n-1] = 0;
		pq.push({0, {n-1, n-1}});
		while(!pq.empty()) {
			int time = pq.top().first * -1;
			pair<int, int> cur = pq.top().second;
			pq.pop();
			
			// 예전에 들어왔던 `낡은 정보`는 탐색하지 않고 넘겨야함.
			if(time > dist[cur.first][cur.second]) continue;
			
			for(pair<int, int> next : dirs) {
				next += cur;
				if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n) continue;
				if(dist[next.first][next.second] <= time + board[next.first][next.second]) continue;
				
				dist[next.first][next.second] = time + board[next.first][next.second];
				pq.push({dist[next.first][next.second] * -1, next});
			}
		}
		
		cout << "#" << tc << " " << dist[0][0] << "\n";
	}
	
	return 0;
}