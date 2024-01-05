#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(string p) {
    queue<char> q;
    
    int open=0, close=0;
    string u="", v="";
    for(int i=0; i<p.size(); i++) {
        if(p[i] == '(') {
            q.push(p[i]);
            open++;
        } else {
            if(!q.empty()) q.pop();
            close++;
        }
        
        if(open == close) {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    if(q.empty()) {
        if(v == "") return u;
        return u + solution(v);
    }
    
    for(char& c : u) c = (c == '(') ? ')' : '(';
    return "(" + solution(v) + ")" + u.substr(1, u.size()-2);
}