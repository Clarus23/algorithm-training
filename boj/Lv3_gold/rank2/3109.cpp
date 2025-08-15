#include <iostream>
#include <vector>
using namespace std;

/*
  - Idea
  -> DFS // Greedy
    - 작은 행부터 시작. 자기 자신이 갈 수 있는 제일 위쪽 길로 걸어가도록 한다.
	- dfs를 사용하였지만, 문제 조건에 의거해 길을 하나 찾으면(cur == c-1) dfs 탐색을 종료 시킨다.(윗 노드가 아닌 아예 종료)
	- 길을 하나 찾을때마다 ++cnt 를 해준다.

  - 시간복잡도
	-> O(RC)

  - 실행시간 : 124ms
  - 메모리 : 3208kb
*/



const pair<int, int> dirs[3] = { {-1, 1}, {0, 1}, {1, 1} };

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
	return { a.first + b.first, a.second + b.second };
}

bool dfs(pair<int, int> cur, vector<vector<bool>>& road, const pair<int, int> border) {
	if (cur.second == border.second-1) return true;

	for (pair<int, int> dir : dirs) {
		pair<int, int> next = cur + dir;

		if (next.first < 0 || next.first >= border.first) continue;
		if (!road[next.first][next.second]) continue;

		road[next.first][next.second] = false;
		if(dfs(next, road, border)) return true;
	}

	return false;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int r, c;
	cin >> r >> c;

	vector<vector<bool>> road(r, vector<bool>(c));
	for (int row = 0; row < r; ++row) {
		for (int col = 0; col < c; ++col) {
			char a; cin >> a;
			road[row][col] = (a == '.');
		}
	}

	int cnt = 0;
	for (int i = 0; i < r; ++i) {
		dfs({ i, 0 }, road, { r, c }) ? ++cnt : cnt;
	}

	cout << cnt;

	return 0;
}