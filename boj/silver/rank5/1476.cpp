#include <iostream>
using namespace std;

int main(void) {
	int e=0,s=0,m=0;
	cin >> e >> s >> m;

	int e2=0,s2=0,m2=0;
	for(unsigned int year=1;;year++) {
		e2=(year%15)?(year%15):15;
		s2=(year%28)?(year%28):28;
		m2=(year%19)?(year%19):19;
		
		if(e2==e && s2==s && m2==m) {
			cout << year;
			break;
		}
	}
	
	return 0;
}
