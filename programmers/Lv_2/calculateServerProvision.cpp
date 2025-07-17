#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    int curServer = 0;
    queue<pair<int, int>> q;
    for(int time=0; time<players.size(); time++) {
        if(!q.empty()) {
            if(time == q.front().second) {
                curServer -= q.front().first;
                q.pop();
            }
        }
        
        int addServer = players[time]/m - curServer;
        if(addServer <= 0) continue;
        
        curServer += addServer;
        answer += addServer;
        q.push({addServer, time+k});
    }
    
    return answer;
}