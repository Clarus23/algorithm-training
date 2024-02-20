#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getTime(string time) {
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3));
    return hour*60 + minute;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<string, int>> wait;
    sort(plans.begin(), plans.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[1] < b[1];
    });
    
    for(int i=0; i<plans.size()-1; i++) {
        int curEnd = getTime(plans[i][1]) + stoi(plans[i][2]);
        int nextStart = getTime(plans[i+1][1]);
        
        if(curEnd == nextStart) answer.push_back(plans[i][0]);
        else if(curEnd > nextStart) wait.push_back({plans[i][0], curEnd-nextStart});
        else {
            answer.push_back(plans[i][0]);
            while(!wait.empty()) {
                pair<string, int> task = wait.back(); wait.pop_back();
                curEnd += task.second;

                if(curEnd == nextStart) { answer.push_back(task.first); break; }
                if(curEnd > nextStart) { wait.push_back({task.first, curEnd-nextStart}); break; }

                answer.push_back(task.first);
            }
        }
    } answer.push_back(plans.back()[0]);
    
    while(!wait.empty()) { answer.push_back(wait.back().first); wait.pop_back(); }
    
    return answer;
}