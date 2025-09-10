#include <iostream>
#include <vector>
using namespace std;

/*
 * # 풀이 아이디어: 플로이드 - 워샬
 * 
 * # 시간복잡도: O(N^3)
 * 
 * # 메모리: 3,080 kb
 * # 실행시간: 136 ms
 * # 체감난이도: 하
 */

const int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(n));
	for(int i=0; i<m; ++i) {
		int from, to;
		cin >> from >> to;
		graph[from-1][to-1] = 1;
	}
	
	for(int i=0; i<n; ++i) {
		for(int from=0; from<n; ++from) {
			for(int to=0; to<n; ++to) {
				if(graph[from][i] == 0 || graph[i][to] == 0) continue;
				
				graph[from][to] = 1;
			}
		}
	}
	
	int ans = 0;
	for(int i=0; i<n; ++i) {
		int cond = 1;
		for(int j=0; j<n; ++j) {
			cond += graph[i][j];
			cond += graph[j][i];
		}
		
		if(cond == n) ++ans;
	}
	
	cout << ans;
	
	return 0;
}
