#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m; cin >> n >> m;
	while(m--) {
		int a; cin >> a;
		int prev = 2e9;
		while(a--) {
			int b; cin >> b;
			if(prev < b) {
				cout << "No";
				return 0;
			}
			prev = b;
		}
	}
	
	cout << "Yes";
	return 0;
}
