#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> stack;
    
    for(int i=progresses.size()-1; i>=0; i--) //stack에 대한 함수를 사용하기 위해 역순으로 집어넣음.
        stack.push_back((100-progresses[i])/speeds[i] + (((100-progresses[i])%speeds[i]) ? 1 : 0));
    
    for(int day=1; !stack.empty(); day++) {
        int todayJob = 0;
        while(!stack.empty() && stack.back()-day <= 0) {
            stack.pop_back();
            todayJob++;
        }
        if(todayJob) answer.push_back(todayJob);
    }
    
    return answer;
}