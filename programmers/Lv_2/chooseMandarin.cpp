#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
	return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> tangerineMap;
    sort(tangerine.begin(), tangerine.end());
    
    for(int size : tangerine) {
        if(tangerineMap.find(size) == tangerineMap.end()) tangerineMap.insert({size, 1});
        else tangerineMap[size]++;
    }
    
    vector<pair<int,int>> tangerines(tangerineMap.begin(), tangerineMap.end());
    sort(tangerines.begin(), tangerines.end(), compare);
    
    while(k > 0 && !tangerines.empty()) {
        k -= tangerines.back().second;
        tangerines.pop_back();
        answer++;
    }
    
    return answer;
}