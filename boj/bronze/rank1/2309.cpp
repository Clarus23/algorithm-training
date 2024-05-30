#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> dwarfs(9);
	vector<bool> temp(9, false);
	for(int i=0; i<7; i++) temp[i] = true;
	
	for(int i=0; i<9; i++) cin >> dwarfs[i];
	sort(dwarfs.begin(), dwarfs.end());
	
	do {
		int sum = 0;
		for(int i=0; i<9; i++)
			if(temp[i]) sum += dwarfs[i];
		if(sum == 100) break;
	} while(prev_permutation(temp.begin(), temp.end()));
	
	
	for(int i=0; i<9; i++) if(temp[i]) cout << dwarfs[i] << '\n';	
	
	return 0;
}
