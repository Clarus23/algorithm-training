#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    set<int> broCake;
    map<int, int> baseCake;
    
    for(int i : topping) {
        if(baseCake.find(i) == baseCake.end()) baseCake[i] = 0;
        else baseCake[i]++;
    }
    
    for(int item : topping) {
        if(!(baseCake[item]--)) baseCake.erase(item);
        broCake.insert(item);
        
        if(baseCake.size() == broCake.size()) answer++;
    }
    
    return answer;
}