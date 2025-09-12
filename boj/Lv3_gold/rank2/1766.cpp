#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* # BOJ G2 1766. 문제집
 * # 풀이 아이디어: 위상 정렬(Topological Sort) with 우선순위 큐(Priority Queue)
 * 	- 문제의 선후 관계 방향 그래프로 모델링. (A -> B: A를 먼저 풀어야 B를 풀 수 있음)
 * 	- 위상 정렬의 조건:
 * 		1. 진입 차수(in-degree, 자신을 가리키는 간선의 수)가 0인 정점을 선택한다.
 * 		2. 해당 정점과 연결된 간선들을 모두 제거한다. (= 연결된 정점들의 진입 차수를 1씩 감소시킨다.)
 * 		3. 1-2 과정을 반복한다.
 * 	- 추가 조건: "가능하면 쉬운 문제부터 풀어야 한다" -> "가능하면 문제 번호가 작은 것부터 풀어야 한다".
 * 		- 진입 차수가 0인 정점들 중에서 **가장 번호가 작은 정점**을 항상 우선적으로 선택.
 * 		- 진입 차수가 0인 정점들을 저장하는 자료구조로 일반 큐(Queue) 대신 **최소 힙(Min-Heap)** 역할인 **우선순위 큐(Priority Queue)**를 사용.
 * 
 * # 시간복잡도: O((N+M)*log(N))
 * 
 * # 메모리: 3,944 kb
 * # 실행시간: 32 ms
 * # 체감난이도: 하
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> inOrder(n+1);
	vector<vector<int>> graph(n+1);
	for(int i=0; i<m; ++i) {
		int from, to;
		cin >> from >> to;
		
		graph[from].push_back(to);
		++inOrder[to];
	}
	
	// C++의 priority_queue는 기본적으로 Max-Heap.
	// Min-Heap으로 사용하기 위해, 값을 음수로 바꾸어 저장.
	priority_queue<int> pq;
	for(int i=1; i<=n; ++i) if(!inOrder[i]) pq.push(-1 * i);
	
	while(!pq.empty()) {
		int cur = -1 * pq.top(); pq.pop();
		cout << cur << " ";
		
		for(int next : graph[cur]) {
			if(--inOrder[next]) continue;
			
			pq.push(-1 * next);
		}
	}
	
	return 0;
}
