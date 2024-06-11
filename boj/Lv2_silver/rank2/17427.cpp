#include <iostream>
using namespace std;

int main(void) {
	int n=0; cin >> n;
	
	long long sum=0;
	for(int i=1; i<=n; i++) sum += (i*(n/i));
	cout << sum;
	
	return 0;
}
