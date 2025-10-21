#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string str; cin >> str;
	
	int size = str.size();
	int windowSize=0;
	int minSwitch = 2e9;
	for(char c : str) {
		windowSize += (c == 'a') ? 1 : 0;
	}
	
	for(int start=0; start<size; ++start) {
		int curSwitch=0;
		for(int i=0; i<windowSize; ++i) {
			int cur = i+start;
			cur %= size;
			
			curSwitch += (str[cur] == 'b') ? 1 : 0;
		}
		
		minSwitch = (curSwitch < minSwitch) ? curSwitch : minSwitch;
	}
	
	cout << minSwitch;
	
	return 0;
}
