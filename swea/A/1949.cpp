#include <iostream>
#include <vector>
using namespace std;

/*
	풀이 아이디어 : DFS 탐색
		- 사방에 나보다 작은 녀석들이 없을때까지 dfs 탐색, 최대 경로 갱신
		- bool 변수를 이용한 단 한번 깎아내기 작업 수행.
	
	메모리: 6016kb
	실행시간: 8ms
*/

int n, k;
int maxDistance = 0;
const pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
	a.first += b.first;
	a.second += b.second;
}

void dfs(vector<vector<int>>& map, vector<vector<bool>>& isVisited, bool dig, int distance, pair<int, int> cur) {
	bool theEnd = true;
	
	for(pair<int, int> next : dirs) {
		next += cur;
		
		if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n
		|| isVisited[next.first][next.second]) continue;
		
		int diff = map[next.first][next.second] - map[cur.first][cur.second];
		if(diff >= 0) {
			if(dig) continue;
			if(diff >= k) continue;
			
			theEnd = false;
			int temp = map[next.first][next.second];
			
			map[next.first][next.second] = map[cur.first][cur.second] - 1;
			isVisited[next.first][next.second] = true;
			dfs(map, isVisited, true, distance+1, next);
			map[next.first][next.second] = temp;
			isVisited[next.first][next.second] = false;
		} else {
			theEnd = false;
			
			isVisited[next.first][next.second] = true;
			dfs(map, isVisited, dig, distance+1, next);
			isVisited[next.first][next.second] = false;
		}
	}
	
	if(theEnd) maxDistance = (distance > maxDistance) ? distance : maxDistance;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int t; cin >> t;
	for(int tc=1; tc<=t; ++tc) {
		cin >> n >> k;
		
		int height = 0;
		vector<pair<int, int>> peaks;
		vector<vector<int>> map(n, vector<int>(n));
		for(int row=0; row<n; ++row) {
			for(int col=0; col<n; ++col) {
				cin >> map[row][col];
				
				if(map[row][col] < height) continue;
				if(map[row][col] > height) {
					height = map[row][col];
					peaks.clear();
				} peaks.push_back({row, col});
			}
		}
		
		maxDistance = 0;
		for(pair<int, int>& peak : peaks) {
			vector<vector<bool>> isVisited(n, vector<bool>(n, false));
			isVisited[peak.first][peak.second] = true;
			dfs(map, isVisited, false, 1, peak);
		}
		
		cout << "#" << tc << " " << maxDistance << "\n";
	}
	
	return 0;
}