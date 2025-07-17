#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 2e9;
    
    int max = *max_element(diffs.begin(), diffs.end())+1;
    int min = 1;
    while(min < max) {
        bool isSuccess = true;
        int level = (max + min)/2;
        
        long long time = 0;
        for(int i=0; i<diffs.size(); i++) {
            if(diffs[i] > level) time += (diffs[i] - level)*(times[i] + times[i-1]);
            
            time += times[i];
            
            if(time > limit) {
                isSuccess = false;
                break;
            }
        }

        if(isSuccess) {
            answer = (answer < level) ? answer : level;
            max = level;
        } else min = level+1;
    }
    
    return answer;
}
