#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
	if(num<=1) return false;
	for(int i=2; i*i<=num; i++) if(!(num%i)) return false;
	return true;
}

int main(void) {
	int n=0;
	cin >> n;
	vector<int> v(n,0);
	for(int i=0; i<n; i++) cin >> v[i];
	
	int cnt=0;
	for(int i=0; i<n; i++) if(isPrime(v[i])) cnt++;
	
	cout << cnt;
	
	return 0;
}
