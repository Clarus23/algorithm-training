#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(unsigned char c: s) {
        if(c>='A' && c<='Z') {
            c+=n;
            if(c>'Z') c-=26;
            answer.push_back(c);
        } else if(c>='a' && c<='z') {
            c+=n;
            if(c>'z') c-= 26;
            answer.push_back(c);
        } else answer.push_back(' ');
    }
    return answer;
}