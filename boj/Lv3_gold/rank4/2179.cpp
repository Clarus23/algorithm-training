#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	# [BOJ] G4 2179 비슷한 단어
	## 해법: Sorting
	## 시간복잡도: O(N*logN + N*L)
	## 메모리: 2,816 kb
	## 실행시간: 12 ms
*/

bool cond(pair<string, int> a, pair<string, int> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<pair<string, int>> words(n);
	
	for(int i=0; i<n; ++i) {
		string word; cin >> word;
		words[i] = {word, i};
	}
	
	
	int max = 0;
	pair<string, int> s = words[0];
	pair<string, int> t = words[1];
	
	sort(words.begin(), words.end(), cond);
	for(int i=1; i<n; ++i) {
		int prev = 0;
		while(i - prev++) {
			pair<string, int> a = words[i-prev];
			pair<string, int> b = words[i];
			
			int cur = 0;
			while(cur < b.first.size() && a.first[cur] == b.first[cur]) ++cur;
			
			if(max > cur) break;
			
			pair<string, int> s_cand = (a.second < b.second ? a : b);
			pair<string, int> t_cand = (a.second > b.second ? a : b);
			
			if(max < cur 
			|| (max == cur && s.second > s_cand.second) 
			|| (max == cur && s.second == s_cand.second && t.second > t_cand.second)) {
				max = cur;
				s = s_cand;
				t = t_cand;
			}
		}
	}
	
	cout << s.first << "\n" << t.first;
	
	return 0;
}
