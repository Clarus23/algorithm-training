#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> stack;
    
    for(char c : s) {
        if(c == '(') stack.push_back('(');
        else {
            if(stack.empty()) {
                answer = false; break;
            } else if(stack.back() == ')') {
                answer = false; break;
            } else stack.pop_back();
        }
    }
    
    if(!stack.empty()) answer = false;

    return answer;
}