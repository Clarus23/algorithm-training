#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* # BOJ G3 2143. 두 배열의 합
 * # 풀이 아이디어: 누적 합 + 이분 탐색
 *	- A배열과 B배열에서 각각 만들 수 있는 모든 부배열의 합을 저장.
 * 	- 두 벡터 중 하나를 정렬(`bSum`)
 * 	- 모든 `aSum`의 원소 `a`에 대하여, `t-a`의 값을 `bSum`에서 찾는다.
 * 	- `bSum`이 정렬되어 있으므로 이분탐색(binary search)를 이용해 `t-a` 값을 가진 원소의 개수 찾을 수 있음.
 * 	- `upper_bound(): value를 초과하는 값 중 첫 원소 반환` `lower_bound(): value 이상 값 중 첫 원소 반환`
 * 	- `t-a` 원소의 개수 = upper_bound(begin(), end(), t-a) - lower_bound(begin(), end(), t-a)
 * 	- 모든 a에 대해 위 과정을 반복.
 * 
 * # 시간복잡도: O(N^2 * logM)
 * 	- `aSum` 생성: O(n^2)
 * 	- `bSum` 생성: O(m^2)
 * 	- `bSum` 정렬: O(m^2 * log(m^2))
 * 	- `aSum` 순회하며 `bSum`에서 이진탐색: O(n^2 * log(m^2))
 
 * # 메모리: 8,304 kb
 * # 실행시간: 120 ms
 * # 체감난이도: 상
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t, n, m;
	cin >> t;
	
	cin >> n;
	vector<int> arrA(n);
	for(int& it : arrA) cin >> it;
	cin >> m;
	vector<int> arrB(m);
	for(int& it : arrB) cin >> it;
	
	vector<int> aSum, bSum;	// 각 배열의 모든 부배열의 합을 저장할 벡터
	
	// A 배열의 모든 부배열의 합
	for(int i=0; i<n; ++i) {
		int sum = arrA[i];
		aSum.push_back(sum);
		for(int j=i+1; j<n; ++j) {
			sum += arrA[j];
			aSum.push_back(sum);
		}
	}
	
	// B 배열의 모든 부배열의 합
	for(int i=0; i<m; ++i)  {
		int sum = arrB[i];
		bSum.push_back(sum);
		for(int j=i+1; j<m; ++j) {
			sum += arrB[j];
			bSum.push_back(sum);
		}
	} sort(bSum.begin(), bSum.end());	// bSum 배열 정렬
	
	long long ans = 0;
	// aSum의 각 원소에 대해, 합이 t가 되는 bSum의 원소의 개수 찾음.
	for(int a=0; a<aSum.size(); ++a) {
		// aSum[a] + target = t 가 되어야 하므로, 찾아야 할 값은 t - aSum[a]
		int target = t - aSum[a];
		// bSum에서 target 값의 개수를 이진 탐색으로 찾아서 더해준다.
		ans += (upper_bound(bSum.begin(), bSum.end(), target) - lower_bound(bSum.begin(), bSum.end(), target));
	}
	
	cout << ans;
	
	return 0;
}
