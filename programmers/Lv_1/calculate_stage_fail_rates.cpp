#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class StageNFailRate {
public:
    int stage;
    double failRate;
    
    StageNFailRate() {}
    StageNFailRate(int stage, double failRate) { this->stage = stage; this->failRate = failRate; }
};

bool compare(StageNFailRate a, StageNFailRate b) {
    bool flag = false;
    
    if(a.failRate > b.failRate) flag = true;
    else if(a.failRate == b.failRate && a.stage < b.stage) flag = true;
    
    return flag;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<StageNFailRate> stageNFailRates;
    
    sort(stages.begin(), stages.end());
    
    int challenger = stages.size();
    int failer = 0; int stage=1;
    for(int i=0; i<stages.size(); i++) {
        if(stages[i] == stage) failer++;
        else if(stages[i] > stage) {
            stageNFailRates.push_back(StageNFailRate(stage, (double)failer/challenger));
            stage++; challenger-=failer; failer=0; i--;
            
            if(challenger == 0) break;
            else continue;
        }
    }
    
    while(stage <= N) {
        if(challenger != 0) {
            stageNFailRates.push_back(StageNFailRate(stage, (double)failer/challenger));
            challenger-=failer; failer=0;
        } else stageNFailRates.push_back(StageNFailRate(stage, 0));
        
        stage++;
    }

    sort(stageNFailRates.begin(), stageNFailRates.end(), compare);
    
    for(StageNFailRate iter : stageNFailRates) answer.push_back(iter.stage);
    
    return answer;
}