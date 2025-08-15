#include <iostream>
#include <vector>
using namespace std;

/*
	풀이 아이디어 : 수식
		- +1, +2 물뿌리개를 하루에 한번씩 사용함
		- 이 조건에 따르면 두가지 필수 조건을 알아낼 수 있음
			1. 나무의 총 길이 합은 무조건 3의 배수여야함.
			2. 홀수길이의 나무의 개수가 +1 물뿌리개 사용량 보다 작거나 같아야함.
		- 이 2가지 조건을 모두 만족하면 `YES` 아니면 `NO`를 출력.
	
	시간 복잡도: O(N)
	
	메모리: 2412kb
	수행시간: 8ms
*/

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin >> n;
	int sumOfHeights = 0;
	int oddTrees = 0;
	vector<int> trees(n);
	for(int& tree : trees) {
		cin >> tree;
		oddTrees += (tree%2);
		sumOfHeights += tree;
	}
	
	if((sumOfHeights%3) || (sumOfHeights/3 < oddTrees)) {
		cout << "NO";
		return 0;
	}
	
	cout << "YES";
	return 0;
}