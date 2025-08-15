#include <iostream>
#include <vector>
using namespace std;

/*
	풀이 아이디어
	start, target, end -> pointer 생성
	[start, target) => 오름차순 검색 two-pointer
	[target, end) => 내림차순 검색 two-pointer

	오름차순 검색한 개수 * 내림차순 검색한 개수 => (start, end) 까지의 우뚝 솟은 산 개수
	그 후 start를 end로 바꿔서 반복

	시간복잡도: O(N)
	시간:	88	 ms
	메모리:	6216 kb
*/

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		int n; cin >> n;
		vector<int> mountains(n);
		for (int& it : mountains) cin >> it;

		int ans = 0;
		int start = 0, end = 0;
		int target = 0;
		while (target < mountains.size()-1 && end < mountains.size()-1) {
			bool isTheEnd = false;
			int ascNum = 0, descNum = 0;
			// -> start, target 을 이용한 오름차순 two-pointer
			while (mountains[target + 1] > mountains[target]) {
				++ascNum;
				if (++target == mountains.size() - 1) {
					isTheEnd = true;
					break;
				}
			} if (isTheEnd) break; // target이 범위를 나감. 탐색 종료

			// 오름차순이 없다면 다음 탐색 시작
			if (target == start) {
				++start; ++target;
				continue;
			}
			
			end = target;
			// -> target, end 를 이용한 내림차순 tow-pointer
			while (mountains[end + 1] < mountains[end]) {
				++descNum;
				if (++end == mountains.size() - 1) {
					isTheEnd = true;
					break;
				}
			}
			
			if (end > target) ans += (ascNum * descNum);
			start = end;
			target = end;
		}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}