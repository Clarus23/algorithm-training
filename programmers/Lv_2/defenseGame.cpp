#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    vector<int> prevRound;
    make_heap(prevRound.begin(), prevRound.end());  //algorithm 헤더의 make_heap함수로 max_heap을 만듦.
    for(int round=0; round<enemy.size(); round++) {
        n -= enemy[round];
        prevRound.push_back(enemy[round]);
        push_heap(prevRound.begin(), prevRound.end());
        
        if(n >= 0) continue;
        if(!k--) return round;
        
        pop_heap(prevRound.begin(), prevRound.end());
        n += prevRound.back();
        prevRound.pop_back();
    }
    
    return enemy.size();
}