#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> stack;
    
    while(n) {
        stack.push_back(n%3);
        n /= 3;
    }
    
    for(int i=0; i<stack.size(); i++) answer += stack[i] * (int)pow(3, (stack.size()-1)-i);
    
    return answer;
}