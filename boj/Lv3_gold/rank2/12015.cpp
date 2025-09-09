#include <iostream>
#include <vector>
using namespace std;

/*
 * # 풀이 아이디어: DP + Binary Search
 * 	- lis[i] -> i번째 길이의 마지막 값 中 최소값.
 * 	- Binary Search를 이용해 lis[] 값을 i마다 update
 * 
 * # 시간복잡도: O(n*log(n))
 * 
 * # 메모리: 9,836 kb
 * # 실행시간: 160 ms
 * # 체감난이도: 하
 */
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<int> arr(n);
	vector<int> lis(n);
	
	int size = 0;
	for(int i=0; i<n; ++i) {
		cin >> arr[i];
		
		int s=0, e=size;
		while(s < e) {
			int m = (s+e)/2;
			
			if(lis[m] < arr[i]) s = m+1;
			else e = m;
		}
		
		lis[e] = arr[i];
		if(e == size) ++size;
	}
	
	cout << size;
	
	return 0;
}
