#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p=0;
    int y=0;
    
    for(char c: s) {
        if(c>=65 && c<=90) c += 32;
        
        if(c == 'p') p++;
        else if(c == 'y') y++;
        else continue;
    }
    answer = (p==y) ? true : false;
    
    return answer;
}