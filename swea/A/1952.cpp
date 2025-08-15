#include <iostream>
using namespace std;

/*
	풀이 아이디어: dfs + backtracking

	month 배열에 (현재일*일일권 가격, 1개월권 가격) 中 작은 값 저장.
	dfs를 이용해서 현재 월에서 3개월권을 사용한 경우, 사용하지 않은 경우를 각각 탐색
	현재 코스트가 최소코스트 이상이면 Pruning
	depth가 12이상이면 최소값 Update

	메모리: 396kb
	시간: 4ms

	난이도: 중하
*/

int costs[4];
int months[12];
int minCost;

void dfs(int curCost, int depth) {
	if (curCost >= minCost) return;
	if (depth >= 12) {
		minCost = (curCost < minCost) ? curCost : minCost;
		return;
	}

	dfs(curCost + months[depth], depth + 1);
	dfs(curCost + costs[2], depth + 3);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		for (int& cost : costs) cin >> cost;

		for (int& month : months) {
			cin >> month;
			month = (costs[0] * month < costs[1]) ? costs[0] * month : costs[1];
		}

		minCost = costs[3];
		dfs(0, 0);
		cout << "#" << tc << " " << minCost << "\n";
	}

	return 0;
}