#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
	a.first += b.first;
	a.second += b.second;
}

char findFunc(vector<char>& parent, char code) {
	if(parent[code - 'a'] != code) {
		parent[code - 'a'] = findFunc(parent, parent[code - 'a']);
	}
	
	return parent[code - 'a'];
}

void unionFunc(vector<char>& parent, vector<int>& rank, char code1, char code2) {
	char u = findFunc(parent, code1);
	char v = findFunc(parent, code2);
	
	if(u == v) return;
	
	if(rank[u - 'a'] > rank[v - 'a']) {
		char temp = u;
		u = v;
		v = temp;
	}
	
	parent[u - 'a'] = v;
	if(rank[u - 'a'] == rank[v - 'a']) ++rank[v - 'a'];
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	// 지도 입력
	vector<vector<int>> map(n, vector<int>(m));
	for(int row=0; row<n; ++row) {
		for(int col=0; col<m; ++col) {
			cin >> map[row][col];
		}
	}
	
	// 각각의 섬들에 섬 코드 부여
	char iCode = 'a';
	for(int row=0; row<n; ++row) {
		for(int col=0; col<m; ++col) {
			if(map[row][col] != 1) continue;
			
			queue<pair<int, int>> q;
			map[row][col] = iCode;
			q.push({row, col});
			while(!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();
				
				for(pair<int, int> next : dirs) {
					next += cur;
					
					if(next.first < 0 || next.first >= n || next.second < 0 || next.second >=m
					|| map[next.first][next.second] != 1) continue;
					
					map[next.first][next.second] = iCode;
					q.push(next);
				}
			}
			++iCode;
		}
	}
	
	// 각 섬들을 잇는 모든 다리를 priority_queue(최소 힙)에 집어 넣는다.
	priority_queue<pair<int, pair<char, char>>> pq;
	for(int row=0; row<n; ++row) {
		for(int col=0; col<m; ++col) {
			if(!map[row][col]) continue;
			
			char curCode = map[row][col];
			for(pair<int, int> dir : dirs) {
				pair<int, int> cur = {row, col};
				int distance = 0;
				
				while(true) {
					cur += dir;
					
					if(cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= m
					|| map[cur.first][cur.second] == curCode) break;
					
					if(map[cur.first][cur.second] && map[cur.first][cur.second] != curCode) {
						if(distance < 2) break;
						
						pq.push({-1 * distance, {curCode, map[cur.first][cur.second]}});
						break;
					}
					
					++distance;
				}
			}
		}
	}
	
	// 가장 짧은 다리부터 건설. cycle이 생기지 않도록 union - find 사용
	vector<char> parent(iCode - 'a');
	vector<int> rank(iCode - 'a');
	for(int i='a'; i<iCode; ++i) parent[i - 'a'] = i;
	
	int lengthOfBridges = 0;
	int numOfBridges = 0; // bridge의 개수가 (iCode - 'a') - 1 여야함.
	while((numOfBridges < iCode - 'a') && !pq.empty()) {
		int distance = pq.top().first * -1;
		pair<char, char> islands = pq.top().second;
		pq.pop();
		
		char groupA = findFunc(parent, islands.first);
		char groupB = findFunc(parent, islands.second);
		
		if(groupA == groupB) continue;
		
		++numOfBridges;
		lengthOfBridges += distance;
		unionFunc(parent, rank, groupA, groupB);
	}
	
	cout << ((numOfBridges == (iCode - 'a')-1) ? lengthOfBridges : -1);
	
	return 0;
}