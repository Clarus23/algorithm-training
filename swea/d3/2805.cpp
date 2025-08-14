#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	풀이 아이디어
	단순 구현

	문제에 주어진 내접하는 마름모에 해당하는 값들을 더해서 반환

	메모리 396kb
	시간 4ms

	난이도 : 하
*/

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		int n; cin >> n;
		vector<string> field(n);
		for (string& row : field) cin >> row;


		int value = 0;
		for (int row = 0; row < n / 2; ++row) {
			for (int col = (n / 2) - row; col <= (n / 2) + row; ++col)
				value += (field[row][col] - '0');
		}
		for (int row = n / 2; row < n; ++row) {
			for (int col = (n / 2) - (n - 1 - row); col <= (n / 2) + (n - 1 - row); ++col)
				value += (field[row][col] - '0');
		}


		cout << "#" << tc << " " << value << "\n";
	}

	return 0;
}
