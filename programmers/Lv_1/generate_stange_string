#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool evenFlag = true;
    
    for(char c: s) {
        if(c == ' ') {
            answer += ' ';
            evenFlag = true;
        } else if(evenFlag) {
            answer += toupper(c);
            evenFlag = false;
        } else {
            answer += tolower(c);
            evenFlag = true;
        }
    }
    
    return answer;
}