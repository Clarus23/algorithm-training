#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector<int> subBelt;
    
    int cnt = 0;
    for(int i=1; i<=order.size(); i++) {
        if(order[cnt] == i) {
            cnt++; answer++;
            continue;
        }
        
        while(!subBelt.empty()) {
            if(subBelt.back() != order[cnt]) break;
            
            subBelt.pop_back();
            answer++; cnt++;
        }
        
        subBelt.push_back(i);
    }
    
    while(!subBelt.empty()) {
        if(subBelt.back() != order[cnt]) break;
        
        subBelt.pop_back();
        answer++; cnt++;
    }
    
    return answer;
}