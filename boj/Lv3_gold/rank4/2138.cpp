#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	# [BOJ] G4 2138 전구와 스위치
	## 해법: Greedy Algorithm
	## 시간복잡도: O(N)
	## 메모리: 2,392 kb
	## 실행시간: 0 ms
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	string temp, tempAns;
	cin >> temp >> tempAns;
	
	vector<bool> click0(n);
	vector<bool> nonclick0(n);
	vector<bool> ans(n);
	
	for(int i=0; i<n; ++i) {
		bool cur = (temp[i] == '1');
		
		click0[i] = cur;
		nonclick0[i] = cur;
		
		ans[i] = (tempAns[i] == '1');
	}
	click0[0] = !click0[0];
	click0[1] = !click0[1];
	
	int cand[2] = {1, 0};
	for(int i=1; i<n; ++i) {
		if(click0[i-1] != ans[i-1]) {
			++cand[0];
			
			click0[i-1] = !click0[i-1];
			click0[i] = !click0[i];
			click0[i+1] = !click0[i+1];
		}
		
		if(nonclick0[i-1] != ans[i-1]) {
			++cand[1];
			
			nonclick0[i-1] = !nonclick0[i-1];
			nonclick0[i] = !nonclick0[i];
			nonclick0[i+1] = !nonclick0[i+1];
		}
	}
	
	cand[0] = (click0[n-1] == ans[n-1] ? cand[0] : 2e9);
	cand[1] = (nonclick0[n-1] == ans[n-1] ? cand[1] : 2e9);
	
	int clickCnt = (cand[0] < cand[1] ? cand[0] : cand[1]);
	cout << (clickCnt == 2e9 ? -1 : clickCnt);
	
	return 0;
}
