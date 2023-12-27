#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void combination(map<string, int>& setMenu, string order, int r) {
    int n = order.size();
    vector<bool> v(n-r, false);
    v.insert(v.end(), r, true);
    
    do {
        string candidate = "";
        for(int i=0; i<n; i++)
            if(v[i]) candidate += order[i];
        
        if(setMenu.find(candidate) != setMenu.end()) setMenu[candidate]++;
        else setMenu[candidate] = 1;
    } while(next_permutation(v.begin(), v.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int r : course) {
        map<string, int> setMenu;
        for(string order : orders) {
            sort(order.begin(), order.end());
            if(order.size() == r) {
                if(setMenu.find(order) != setMenu.end()) setMenu[order]++;
                else setMenu[order] = 1;
            } else if(order.size() > r) combination(setMenu, order, r);
        }
        
        vector<pair<string, int>> temp(setMenu.begin(), setMenu.end());
        sort(temp.begin(), temp.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
        });
        
        int max = temp[0].second;
        for(int i=0; i<temp.size(); i++) {
            if(temp[i].second < max || temp[i].second < 2) break;
            answer.push_back(temp[i].first);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}