#include <iostream>
#include <vector>
using namespace std;

/*
	풀이 아이디어 : 수학
		- diffSum 높이 까지 키우는데 필요한 최적의 일수 day : (diffSum/3)*2 + diffSum%3
		- day 일 중 +1 키워진 날의 개수 plus1 : day/2 + day%2
		- 홀수 만큼 커야하는 나무들의 개수 oddDiff
		- 만약 plus1 이 oddDiff 보다 적다면 그 차이(diffDay)만큼 기다려야함.
		- day가 홀수였다면 -> diffDay*2 일만큼
		- day가 짝수였다면 -> diffDay*2 - 1 일만큼 기다려야함.
		- 이를 일반화 하면 -> diffDay*2 + diffDay%2 - 1 일 만큼 기다려야함.
		
		=> 위의 모든 조건을 통과하면 정답이 도출 됨.
		
	시간 복잡도: O(N)
	
	메모리: 396kb
	실행시간: 5ms
*/

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int t; cin >> t;
	for(int tc=1; tc<=t; ++tc) {
		int n; cin >> n;
		
		int maxHeight = 0;
		vector<int> trees(n);
		for(int& tree : trees) {
			cin >> tree;
			maxHeight = (tree > maxHeight) ? tree : maxHeight;
		}
		
		int diffSum = 0;
		int oddDiff = 0;
		for(int tree : trees) {
			int diff = maxHeight - tree;
			
			diffSum += diff;
			oddDiff += (diff%2);
		}
		
		int day = (diffSum/3)*2 + (diffSum%3);
				
		int plus1 = oddDiff - ((day/2) + (day%2));
		
		if(plus1 > 0) day += (plus1*2 + day%2 - 1);
		
		cout << "#" << tc << " " << day << "\n";
	}
	
	return 0;
}