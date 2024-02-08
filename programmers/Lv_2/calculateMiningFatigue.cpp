#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    const int mining = min((picks[0] + picks[1] + picks[2])*5, (int)minerals.size());
    
    vector<tuple<int, int, int>> mineralSet;
    
    tuple<int, int, int> temp = {0, 0, 0};
    for(int i=0; i<mining; i++) {
        if(minerals[i] == "diamond") get<0>(temp)++;
        else if(minerals[i] == "iron") get<1>(temp)++;
        else get<2>(temp)++;
        
        if(i%5==4 || i==mining-1) {
            mineralSet.push_back(temp);
            temp = {0, 0, 0};
        }
    }
    
    sort(mineralSet.begin(), mineralSet.end(), [](const auto& a, const auto& b) {
        int na = 25*get<0>(a) + 5*get<1>(a) + get<2>(a);
        int nb = 25*get<0>(b) + 5*get<1>(b) + get<2>(b);
        
        return (na>=nb);
    });
    
    int fatigue = 0;
    for(auto mineral : mineralSet) {
        if(picks[0]) {
            fatigue += (get<0>(mineral) + get<1>(mineral) + get<2>(mineral));
            picks[0]--; continue;
        }
        
        if(picks[1]) {
            fatigue += (get<0>(mineral)*5 + get<1>(mineral) + get<2>(mineral));
            picks[1]--; continue;
        }
        
        fatigue += (get<0>(mineral)*25 + get<1>(mineral)*5 + get<2>(mineral));
    }
    
    return fatigue;
}