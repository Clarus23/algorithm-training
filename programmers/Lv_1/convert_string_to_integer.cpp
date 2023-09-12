#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    if(s[0] == '+' || s[0] == '-') {
        string s2 = s.substr(1);
        answer = stoi(s2);
        if(s[0] == '-') answer *= (-1);
    } else {
        answer = stoi(s);
    }
    
    return answer;
}