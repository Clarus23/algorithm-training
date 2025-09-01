#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * # 풀이 아이디어: 투 포인터(two-pointer)
 *	- 정렬된 용액의 배열에서 두 용액의 합이 0에 가장 가까운 것을 찾자.
 *	- 배열의 양 끝에서 시작하는 두 개의 포인터(start pointer `sp`, end pointer `ep`)를 사용.
 *	- `sp`는 배열의 시작(가장 작은 값)에서, `ep`는 배열의 끝(가장 큰 값)에서 시작합니다.
 *	- 두 포인터가 가리키는 값의 합을 계산하고, 이 합의 절댓값이 이전에 찾은 최솟값(`minDiff`)보다 작으면 정답과 `minDiff`를 갱신합니다.\
 *		1. 합이 0보다 크면, 합을 줄여야 하므로 더 큰 값인 `ep`를 왼쪽으로 한 칸 이동시킵니다 (`--ep`).
 *		2. 합이 0보다 작으면, 합을 늘려야 하므로 더 작은 값인 `sp`를 오른쪽으로 한 칸 이동시킵니다 (`++sp`).
 *	- 이 과정을 `sp`와 `ep`가 만날 때까지 반복합니다. 합이 0이 되면 최적의 해이므로 즉시 종료합니다.
 *
 * # 시간 복잡도: O(N)
 *	- N은 용액의 수
 *	- 투 포인터 `sp`, `ep`가 배열의 양 끝에서 시작하여 서로를 향해 한칸씩 이동하므로,
 *	  loop는 총 N번 수행.
 *
 * # 메모리:
 * # 실행시간: 
 * # 체감 난이도: 하
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<int> solutions(n);
	for(int& solution : solutions) cin >> solution;
	
	int solution1 = 0, solution2 = 0;
	int sp = 0, ep = n-1;
	int minDiff = 2e9;
	while(sp < ep) {
		int diff = solutions[ep] + solutions[sp];
		
		if(abs(diff) < minDiff) {
			solution1 = solutions[sp];
			solution2 = solutions[ep];
			minDiff = abs(diff);
		}
		
		if(!diff) break;
		if(diff > 0) --ep;
		else ++sp;
	}
	
	cout << solution1 << " " << solution2;
	
	
	return 0;
}