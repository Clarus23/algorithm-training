#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    sort(arr.begin(), arr.end());
    for(int it: arr) {
        if(it%divisor == 0) answer.push_back(it);
        else continue;
    }
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}