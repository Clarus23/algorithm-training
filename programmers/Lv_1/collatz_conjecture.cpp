#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    
    for(answer=0; answer<500; answer++) {
        if(n == 1) return answer;
        
        n = (n%2 == 0) ? n/2 : (n*3)+1;
    }
    
    return -1;
}