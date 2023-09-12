#include <string>
#include <vector>

using namespace std;

bool divisorIsEnum(int n) {
    int num=0;
    
    for(int i=1; i*i<=n; i++) {
        if(i*i == n) num++;
        else if(n%i == 0) num+=2;
    }
    
    return (num%2 == 0);
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i=left; i<=right; i++) {
        answer += (divisorIsEnum(i)) ? i : (-i);
    }
    
    return answer;
}