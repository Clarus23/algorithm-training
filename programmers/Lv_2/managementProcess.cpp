#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<int> readyQ;
    
    for(int process=0; process<priorities.size(); process++) readyQ.push(process);
    
    while(!readyQ.empty()) {
        int curProcess = readyQ.front(); readyQ.pop();
        int maxPriority = *max_element(priorities.begin(), priorities.end());
        
        if(priorities[curProcess] != maxPriority) readyQ.push(curProcess);
        else if(curProcess == location) break;
        else {
            answer++;
            priorities[curProcess] = 0;
        }
    }
    
    return answer;
}