#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    if(s.size()%2) return 0;
    
    int answer = 0;
    vector<char> stack;
    
    for(char c : s) {
        if(stack.empty()) stack.push_back(c);
        else if(stack.back() == c) stack.pop_back();
        else stack.push_back(c);
    }
    if(stack.empty()) answer = 1;
    
    return answer;
}