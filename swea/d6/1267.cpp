#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	풀이 아이디어 : 위상 정렬
		- 입력을 받을 때, 자신을 후행작업으로 가지는 선행작업이 있다면 inDegree의 개수를 +1
		- 모든 입력이 끝났을 때, inDegree가 0인 노드들은 선행작업이 없는 노드.
		- 큐에 집어넣어 하나씩 출력, BFS 탐색을 수행하며 불린 노드들의 inDegree를 -1
		- 탐색된 노드의 inDegree가 0이 되었다면 q에 삽입.
		- 위를 반복
		
	시간 복잡도: O(V+E)
	
	실행시간:    7ms
	메모리:   6008kb
*/

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	for(int tc=1; tc<=10; ++tc) {
		int v, e;
		cin >> v >> e;
		
		vector<int> inDegree(v, 0);
		vector<vector<int>> graph(v);
		for(int i=0; i<e; ++i) {
			int s, e;
			cin >> s >> e;
			
			++inDegree[e-1];
			graph[s-1].push_back(e-1);
		}
		
		queue<int> q;
		for(int i=0; i<v; ++i) if(!inDegree[i]) q.push(i);
		
		cout << "#" << tc << " ";
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			cout << cur+1 << " ";
			
			for(int next : graph[cur]) {
				if(!inDegree[next]) continue;
				
				if(!(--inDegree[next])) q.push(next);
			}
		}
		cout << "\n";
	}
	
	return 0;
}