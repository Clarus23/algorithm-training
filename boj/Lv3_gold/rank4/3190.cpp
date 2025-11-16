#include <iostream>
#include <vector>
using namespace std;

int n, k, l;

pair<int, int> dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
	a.first += b.first;
	a.second += b.second;
}

bool gameOver(vector<vector<pair<int, int>>>& map, int row, int col) {
	if(row < 1 || row > n || col < 1 || col > n) return true;
	if(map[row][col].first == 2) return true;
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	vector<vector<pair<int, int>>> map(n+1, vector<pair<int, int>>(n+1));
	map[1][1] = {2, 0};
	
	cin >> k;
	while(k--) {
		int row, col;
		cin >> row >> col;
		map[row][col].first = 1;
	}
	
	cin >> l;
	vector<pair<int, char>> dirList(l);
	for(pair<int, char>& dir : dirList) {
		cin >> dir.first >> dir.second;
	}
	
	pair<int, int> head = {1, 1};
	pair<int, int> tail = {1, 1};
	int pt = 0; int dir = 0;
	for(int time=1; ; ++time) {
		// 움직이고
		head += dirs[dir];
		if(gameOver(map, head.first, head.second)) {
			cout << time;
			break;
		}
		
		if(map[head.first][head.second].first != 1) {
			map[tail.first][tail.second].first = 0;
			tail += dirs[map[tail.first][tail.second].second];
		}
		
		// 방향 바꾸고
		if(time == dirList[pt].first) {
			if(dirList[pt].second == 'D') dir = (dir+1)%4;
			else dir = (dir+3)%4;
			++pt;
		}
		
		map[head.first][head.second] = {2, dir};
	}
	
	return 0;
}
