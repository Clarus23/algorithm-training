#include <iostream>
using namespace std;

int main(void) {
	int n=0;
	cin >> n;
	
	int size=0;
	for(int weight=1; weight<=n; weight*=10)
		size += (n-weight+1);
	
	cout << size;
	
	return 0;
}
