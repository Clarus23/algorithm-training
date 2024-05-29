#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int num=0;
	cin >> num;
	vector<int> v(num,0);
	for(int i=0; i<num; i++) cin >> v[i];
	
	sort(v.begin(), v.end());
	
	if(num%2) cout << v[num/2]*v[num/2];
	else cout << v[0]*v[num-1];
	
	return 0;
}
