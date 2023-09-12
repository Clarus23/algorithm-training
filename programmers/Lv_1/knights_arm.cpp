#include <string>
#include <vector>

using namespace std;

int getDiviserNum(int n) {
    int answer=0;
    for(int i=1; i*i<=n; i++) {
        if(i*i == n) answer++;
        else if(n%i == 0) answer+=2;
    }
    
    return answer;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i=1; i<=number; i++) {
        int atack = getDiviserNum(i);
        if(atack > limit) answer += power;
        else answer += atack;
    }
    
    return answer;
}