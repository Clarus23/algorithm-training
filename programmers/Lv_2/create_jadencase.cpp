#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirstChar = true;
    
    for(char c : s) {
        if(c == ' ') {
            isFirstChar = true;
            answer.push_back(c);
            continue;
        }
        
        if(isFirstChar) {
            isFirstChar = false;
            
            if(c >= 'a' && c <= 'z') answer.push_back(c - ('a'-'A'));
            else answer.push_back(c);
        } else {
            if(c >= 'A' && c <= 'Z') answer.push_back(c + ('a'-'A'));
            else answer.push_back(c);
        }
    }

    return answer;
}