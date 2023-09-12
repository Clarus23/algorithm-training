#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    char x; bool start = true;
    int count[2] = {0,};
    
    for(char c : s) {
        if(start) {
            x = c; start = false;
            count[0] = 1; count[1] = 0;
            continue;
        }
        
        (c == x) ? count[0]++ : count[1]++;
        
        if(count[0] == count[1]) {
            answer++; start = true;
            continue;
        }
    }
    if(count[0] != count[1]) answer++;
    
    return answer;
}