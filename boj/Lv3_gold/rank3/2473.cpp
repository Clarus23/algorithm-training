#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * # 풀이 아이디어: 투 포인터(two-pointer)
 * 	- 세 개의 용액을 선택해야 하므로, 0번부터 n-3번까지 용액을 "미리" 선택하고 나머지 2개를 투 포인터를 이용해 탐색한다.
 *
 * # 시간복잡도: O(N^2)
 * 
 * # 메모리: 2160 kb
 * # 실행시간: 28 ms
 * # 난이도: 중하
 */

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<int> solutions(n);
	for(int& solution : solutions) cin >> solution;
	sort(solutions.begin(), solutions.end());
	
	ll minDiff = 1e10;
	vector<int> ansSolution(3);
	for(int p=0; p<n-2; ++p) {
		int sp = p+1, ep = n-1;
		bool isZero = false;
		while(sp < ep) {	
			ll diff = (ll)solutions[p] + solutions[sp] + solutions[ep];
			
			if(abs(diff) < minDiff) {
				ansSolution[0] = solutions[p];
				ansSolution[1] = solutions[sp];
				ansSolution[2] = solutions[ep];
				minDiff = abs(diff);
			}
			
			if(diff == 0) {
				isZero = true;
				break;
			}
			
			if(diff > 0) --ep;
			else ++sp;
		} if(isZero) break;
	}
	
	for(int solution : ansSolution) cout << solution << " ";
	
	return 0;
}
