#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin >> n;
	vector<int> stack(n);
	for(int& s : stack) cin >> s;
	
	int top = n-1;
	int max = stack[top--];
	int cnt = 1;
	while(top>=0) {
		int cur = stack[top--];
		if(cur > max) {
			++cnt;
			max = cur;
		}
	}
	
	cout << cnt;
	
	return 0;
}
