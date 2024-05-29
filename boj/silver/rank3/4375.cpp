#include <iostream>
using namespace std;

int main(void) {
	int n=0;
	while(cin >> n) {
		int target = 1;
		for(int cnt=1;;cnt++) {
			if(!(target%n)) {
				cout << cnt << '\n';
				break;
			}
			
			target = target*10 + 1;
			target %= n;
		}
	}
	
	return 0;
}
