#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    vector<pair<int, int>> stack;
    
    stack.push_back({prices[prices.size()-1], 0});
    for(int i=prices.size()-2; i>=0; i--) {
        int cnt=1;
        while(!stack.empty()) {
            pair<int, int> top = stack.back(); stack.pop_back();
            
            if(top.first < prices[i]) {
                stack.push_back(top);
                break;
            }
            
            cnt += top.second;
        }
        
        stack.push_back({prices[i], cnt});
        answer[i] = cnt;
    }
    
    return answer;
}