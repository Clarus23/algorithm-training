#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	풀이 아이디어 : bitmask + BFS + 완전탐색
		- 선거구가 2개이므로 bitmask를 통해 선거구를 나눌 수 있음
		- 0, 2^n -1은 한개의 선거구만 있는 경우이므로 제외
		- 1010, 0101은 선거구가 반전되어있으나, diff값이 같을 것이란걸 알 수 있음
			-> bool 배열을 만들어 한번만 탐색.

		- 선거구를 나눴다면, bfs탐색을 통해 A선거구, B선거구를 탐색함
		- 각 선거구에서 이어지지 않는 지역이 있다면 다음 탐색 재개

		- 모든 탐색을 끝낸 후, 최소 diff값이 정답.

		** 완전 탐색이 가능한 이유?
			-> N의 조건이 2이상, 10이하 (매우 작음)

	시간 복잡도 :O(N*2^N)

	메모리 : 2024kb
	시간   : 0ms
*/

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	vector<bool> isSelected((1 << n)); // [0 ~ 2^n -1]

	// 인구수 입력
	int sumOfPopulation = 0;
	vector<int> populations(n);
	for (int& it : populations) {
		cin >> it;
		sumOfPopulation += it;
	}

	// 그래프 입력
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		
		for (int j = 0; j < a; ++j) {
			int temp; cin >> temp;
			graph[i].push_back(temp - 1);
		}
	}

	int minDiff = 2e9;
	// 이제부터 sub를 이용해 bitmask할것.
	// 1 bit -> A선거구 / 0 bit -> B선거구
	for (int sub = 1; sub < (1 << n) - 1; ++sub) {
		if (isSelected[sub]) continue;

		// 1010 과 0101의 인구수 차이는 똑같을 것이기 때문에 true 처리
		isSelected[sub] = true;
		isSelected[((~sub)&((1 << n) - 1))] = true;

		// a선거구의 인원을 구함.
		int aPopulation = 0;
		int aStart = -1, bStart = -1;
		int aSize = 0, bSize = 0;
		for (int j = 0; j < n; ++j) {
			if (sub & (1 << j)) {
				aStart = j;
				++aSize;
				aPopulation += populations[j];
			} else {
				bStart = j;
				++bSize;
			}
		}
			
		
		// diff 구하기, 음수라면 -1을 곱해서 양수로 바꿔줌
		int diff = sumOfPopulation - 2 * aPopulation;
		diff *= (diff < 0) ? -1 : 1;

		// diff가 minDiff보다 크거나 같다면 탐색할 필요가 없다.
		if (diff >= minDiff) continue;

		// diff가 mindiff보다 작다면, A선거구와 B선거구가 서로 이어져 있는지를 탐색한다.
		vector<int> isVisited(n, false);
		queue<int> q;

		// A선거구 탐색
		int curSize = 1;
		isVisited[aStart] = true;
		q.push(aStart);
		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int next : graph[cur]) {
				if (!(sub&(1 << next)) || isVisited[next]) continue;

				++curSize;
				isVisited[next] = true;
				q.push(next);
			}
		}
		// A선거구의 구역의 개수가 다르면 다음으로 넘긴다.
		if (curSize != aSize) continue;

		// B선거구 탐색
		curSize = 1;
		isVisited[bStart] = true;
		q.push(bStart);
		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int next : graph[cur]) {
				if ((sub&(1 << next)) || isVisited[next]) continue;

				++curSize;
				isVisited[next] = true;
				q.push(next);
			}
		}
		// B선거구의 구역의 개수까지 같다면, 최소차이를 현재 차이로 업데이트한다.
		// 여기까지 내려왔으면, diff가 무조건 minDiff보다 작다는게 보장되어있다.
		if (curSize == bSize) minDiff = diff;
	}

	cout << ((minDiff == 2e9) ? -1 : minDiff);

	return 0;
}
