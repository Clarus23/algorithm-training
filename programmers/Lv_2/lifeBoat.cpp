#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.rbegin(), people.rend());
    vector<int> heavys(people.begin(), people.begin()+(people.size()/2));
    vector<int> lights(people.begin()+(people.size()/2), people.end());
    
    sort(heavys.begin(), heavys.end());
    
    while(!(heavys.empty() && lights.empty())) {
        int heavy = heavys.back(); //남은 사람중 가장 무거운 사람
        int light = lights.back(); //남은 사람중 가장 가벼운 사람
        
        if(heavys.empty()) {
            if(lights.size() == 1) {
                answer++; break;
            }
            
            heavys.assign(lights.begin(), lights.begin()+(lights.size()/2));
            sort(heavys.begin(), heavys.end());
            lights.assign(lights.begin()+(lights.size()/2), lights.end());
        } else if(heavy + light > limit) {
            heavys.pop_back();
            answer++;
        } else {
            heavys.pop_back();
            lights.pop_back();
            answer++;
        }
    }
    
    return answer;
}