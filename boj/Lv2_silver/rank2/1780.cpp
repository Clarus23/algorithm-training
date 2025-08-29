#include <iostream>
#include <vector>
using namespace std;

/*
 * # 풀이 아이디어: 분할 정복(Divide and Conquer), 재귀(Recursion)
 * - 주어진 종이(영역)가 모두 같은 숫자로 채워져 있는지 확인합니다.
 * - 만약 모두 같은 숫자라면, 해당 숫자의 카운트를 1 증가시키고 재귀를 종료합니다.
 * - 그렇지 않다면, 현재 영역을 동일한 크기의 9개(3x3) 영역으로 자르고, 각 영역에 대해 재귀적으로 동일한 과정을 반복합니다.
 *
 * # 시간복잡도: O(N²)
 * - 최악의 경우(모든 칸이 다를 때) 종이의 모든 칸을 한 번씩 확인해야 합니다.
 * - 종이의 크기가 N x N이므로 총 N²개의 칸이 있어 시간 복잡도는 O(N²)이 됩니다.
 *
 * # 메모리: 20,832 kb
 * # 실행시간: 356 ms
 * # 체감난이도: 하
 */

int n;
int cnt[3] = {0, 0, 0};

void slice(vector<vector<int>>& paper, int startR, int startC, int size) {
	bool isOne = true;
	for(int row=startR; row < startR + size; ++row) {
		for(int col=startC; col < startC + size; ++col) {
			if(paper[row][col] == paper[startR][startC]) continue;
			
			isOne = false;
			break;
		} if(!isOne) break;
	}
	
	if(isOne) {
		++cnt[paper[startR][startC]+1];
		return;
	}
	
	int step = size/3;
	for(int row=0; row<3; ++row)
		for(int col=0; col<3; ++col)
			slice(paper, startR+step*row, startC+step*col, step);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> n;
	vector<vector<int>> paper(n, vector<int>(n));
	for(vector<int>& row : paper) for(int& cell : row) cin >> cell;
	
	slice(paper, 0, 0, n);
	
	cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2];
	
	return 0;
}
