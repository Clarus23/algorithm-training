#include <string>
#include <vector>

using namespace std;

vector<int> divisor(int n) {
    vector<int> result;
    for(int i=1; i*i<=n; i++) {
        if(!(n%i)) result.push_back(i);
    }
    
    return result;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    vector<int> div = divisor(yellow);
    if(div.size() == 1) {
        answer.push_back(yellow/div[0] + 2);
        answer.push_back(div[0] + 2);
    } else {
        for(int it : div) {
            if(2 * (yellow/it + it) == brown-4) {
                answer.push_back(yellow/it + 2);
                answer.push_back(it + 2);
            }
        }
    }
    
    return answer;
}