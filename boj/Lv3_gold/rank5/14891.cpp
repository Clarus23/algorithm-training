#include <iostream>
#include <vector>
using namespace std;

int main() {
	int pointers[4] = {0, 0, 0, 0};
	string gears[4];
	for(int i=0; i<4; ++i) cin >> gears[i];
	
	int k; cin >> k;
	while(k--) {
		int id, dir;
		cin >> id >> dir;
		--id;
		
		int rotation[4] = {0, 0, 0, 0};
		rotation[id] = -1 * dir;
		
		for(int i=id-1; i>=0; --i) {
			if(gears[i][(pointers[i]+2)%8] == gears[i+1][(pointers[i+1]+6)%8]) break;
			
			rotation[i] = -1 * rotation[i+1];
		}
		
		for(int i=id+1; i<4; ++i) {
			if(gears[i][(pointers[i]+6)%8] == gears[i-1][(pointers[i-1]+2)%8]) break;
			
			rotation[i] = -1 * rotation[i-1];
		}
		
		for(int i=0; i<4; ++i) {
			pointers[i] += rotation[i];
			pointers[i] %= 8;
			pointers[i] = (pointers[i] == -1) ? 7 : pointers[i];
		}
	}
	
	int sum=0;
	for(int i=0; i<4; ++i) {
		if(gears[i][pointers[i]] == '0') continue;
		sum |= (1<<i);
	}
	
	cout << sum;
	
	return 0;
}