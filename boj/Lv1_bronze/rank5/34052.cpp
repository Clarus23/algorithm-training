#include <iostream>
using namespace std;

int main() {
	
	int sum = 300;
	for(int i=0; i<4; ++i) {
		int a; cin >> a;
		sum += a;
	}
	
	cout << ((sum > 1800)?"No":"Yes");
	return 0;
}