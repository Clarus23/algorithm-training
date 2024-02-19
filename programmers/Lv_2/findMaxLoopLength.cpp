#include <vector>

using namespace std;

int loop(int cur, vector<bool>& visited, vector<int>& cards) {
    int cnt=0;
    while(!visited[cur]) {
        visited[cur] = true;
        cur = cards[cur]-1;
        cnt++;
    }
    return cnt;
}

int solution(vector<int> cards) {
    int answer = 0;
    
    for(int i=0; i<cards.size(); i++) {
        vector<bool> visited(cards.size(), false);
        int cnt1 = loop(i, visited, cards);
        
        if(cnt1 == cards.size()) continue;
        
        for(int j=0; j<cards.size(); j++) {
            if(visited[j]) continue;
            int cnt2 = loop(j, visited, cards);
            
            answer = (cnt1*cnt2 > answer) ? cnt1*cnt2 : answer;
        }
    }
    
    return answer;
}