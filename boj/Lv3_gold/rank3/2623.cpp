#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * # 풀이 아이디어: 위상 정렬
 * 	- 입력받으며, 나의 부모가 몇명인지 계산.
 *	- 내 부모가 없다면, 그때 q에 집어넣음.
 *	- 이를 반복하며 bfs 수행.
 * 
 * # 시간복잡도: O(N)
 * 
 * # 메모리: 2,172 kb
 * # 실행시간: 0 ms
 * # 체감난이도: 하
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> inOrder(n+1);
	vector<vector<int>> graph(n+1);
	while(m--) {
		int num, prevSinger, singer;
		cin >> num;
		if(num == 0) continue;
		cin >> prevSinger;
		if(num == 1) continue;
		
		for(int i=1; i<num; ++i) {
			cin >> singer;
			graph[prevSinger].push_back(singer);
			++inOrder[singer];
			prevSinger = singer;
		}
	}
	
	vector<int> ans(n); int top = 0;
	queue<int> q;
	for(int i=1; i<=n; ++i) if(!inOrder[i]) q.push(i);
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		ans[top++] = cur;
		
		for(int next : graph[cur]) {
			if(--inOrder[next]) continue;
			
			q.push(next);
		}
	}
	
	if(top != n) cout << 0;
	else for(int it : ans) cout << it << "\n";
	
	return 0;
}
