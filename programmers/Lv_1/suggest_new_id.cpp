#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    regex pointDuplicationStr("(\\.{2,})");
    regex pointStartStr("^\\.(.*)");
    regex pointEndStr("(.*)\\.$");
    smatch match;
    
    string temp = "";
    for(char c : new_id) {
        if(c>='A' && c<='Z') c += ('a'-'A');
        temp += c;
    }
    
    for(char c : temp) {
        if((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-' || c=='_' || c=='.') answer += c;
    }
    
    answer = regex_replace(answer, pointDuplicationStr, "\.");
    
    answer = regex_replace(answer, pointStartStr, "$1");
    answer = regex_replace(answer, pointEndStr, "$1");
    
    if(answer.empty()) answer = "a";
    
    if(answer.size() >= 16) {
        answer = answer.substr(0,15);
        answer = regex_replace(answer, pointEndStr, "$1");
    }
    
    while(answer.size() <= 2) {
        answer += answer[answer.size()-1];
    }
    
    return answer;
}