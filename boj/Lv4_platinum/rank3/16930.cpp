#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
 * # 풀이 아이디어: 너비 우선 탐색(Breadth-First Search, BFS)
 *	- 한 번의 '이동'으로 최대 K칸을 미끄러져 갈 수 있는 조건의 최단 경로 문제입니다.
 *	- 각 '이동'의 가중치가 1로 동일하므로, 최단 '이동 횟수'를 구하는 데에는 BFS가 가장 적합합니다.
 *	- 2차원 배열 `map`을 방문 여부와 시작점으로부터의 거리(이동 횟수)를 기록하는 용도로 사용합니다. (초기값: INF, 벽: -1)
 *	- BFS 로직:
 *		1. 큐에 시작점을 넣고, 시작점의 거리를 0으로 설정합니다.
 *		2. 큐에서 현재 위치를 꺼내, 상하좌우 네 방향으로 각각 1칸부터 K칸까지 이동을 시도합니다.
 *		3. 이동하는 도중 벽을 만나거나 격자 범위를 벗어나면, 해당 방향으로의 탐색을 중단합니다.
 *		4. 만약 이동한 위치가 아직 방문하지 않은 곳이라면(거리가 INF), 거리를 (현재위치 거리 + 1)로 갱신하고 큐에 추가합니다.
 *		5. 만약 이미 방문한 곳이라도, 더 짧은 경로로 도달한 것이 아니므로 더 이상 나아갈 필요가 없습니다. (BFS 특성상 먼저 도달한 경로가 최단 경로임)
 *
 * # 시간복잡도: O(N * M * K)
 *	- N, M은 격자의 세로, 가로 크기이고 K는 최대 이동 거리입니다.
 *	- BFS는 모든 정점과 간선을 한 번씩 방문합니다. 정점의 수는 N*M개 입니다.
 *	- 각 정점에서 최대 4방향으로 K칸씩 탐색하므로, 간선의 총 수는 O(N * M * K)에 비례합니다.
 *	- 따라서 전체 시간 복잡도는 O(N * M * K)가 됩니다.
 *
 * # 메모리: 14,380 kb
 * # 실행시간: 44 ms
 * # 체감난이도: 중상
 */

const int inf = 2e9;
const pair<int, int> dirs[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int n, m, k;

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
	a.first += b.first;
	a.second += b.second;
}
bool operator==(const pair<int, int>& a, const pair<int, int>& b) {
	return (a.first == b.first && a.second == b.second);
}

bool isOutOfRange(const pair<int, int>& coord) {
	return (coord.first < 0 || coord.first >= n || coord.second < 0 || coord.second >= m);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	vector<vector<int>> map(n, vector<int>(m));
	for (int row = 0; row < n; ++row) {
		string temp; cin >> temp;
		for (int col = 0; col < m; ++col)
			map[row][col] = (temp[col] == '#') ? -1 : inf;
	}
	
	pair<int, int> start;
	pair<int, int> goal;
	cin >> start.first >> start.second >> goal.first >> goal.second;
	--start.first; --start.second;
	--goal.first; --goal.second;

	queue<pair<int, int>> q;
	q.push(start);
	map[start.first][start.second] = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (pair<int, int> dir : dirs) {
			pair<int, int> next = cur;
			for (int i = 0; i < k; ++i) {
				next += dir;

				if (isOutOfRange(next) || map[next.first][next.second] == -1) break;
				if (next == goal) {
					cout << map[cur.first][cur.second] + 1;
					return 0;
				}
				if (map[cur.first][cur.second] == map[next.first][next.second]) break;
				if (map[cur.first][cur.second] + 1 < map[next.first][next.second]) {
					map[next.first][next.second] = map[cur.first][cur.second] + 1;
					q.push(next);
				}
			}
		}
	}

	cout << -1;
	return 0;
}
