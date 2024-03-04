#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b){
        return (a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]));
    });
    
    pair<int, int> intercept = {-1, -1};
    for(vector<int> target : targets) {
        if(target[0] > intercept.second) {
            answer++;
            intercept = {target[0], target[1]-1};
        }
        
        intercept.first = target[0];
        intercept.second = min(intercept.second, target[1]-1);
    }
    
    return answer;
}