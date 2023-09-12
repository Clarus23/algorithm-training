#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> honor;
    int minScore=0, minIndex=0;
    
    for(int i=0; i<score.size(); i++) {
        if(i < k) honor.push_back(score[i]);
        else if(minScore < score[i]) honor[minIndex] = score[i];
        else { answer.push_back(minScore); continue; }
        
        minScore = *min_element(honor.begin(), honor.end());
        minIndex = min_element(honor.begin(), honor.end()) - honor.begin();
        answer.push_back(minScore);
    }
    
    return answer;
}