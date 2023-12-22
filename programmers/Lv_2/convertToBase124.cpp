#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int carry = 0;
    while(n) {
        int mod = (n%3 - carry);
        carry = 0;
        while(mod <= 0) {
            carry += 1;
            mod += 3;
        }
        
        n/=3;
        if(!n && mod==3) break;
        answer = (char)(mod+'0') + answer;
    }
    
    for(int i=0; i<answer.size(); i++)
        if(answer[i] == '3') answer[i] = '4';
    
    return answer;
}