#include <iostream>
using namespace std;

int main(void) {
	int n1=0, n2=0;
	cin >> n1 >> n2;
	
	int min = (n1 < n2) ? n1 : n2;
	int max = (n1 > n2) ? n1 : n2;
	while(min) {
		int temp = max%min;
		max = min;
		min = temp;
	}
	
	cout << max << endl << (n1/max)*n2;
	
	return 0;
}
