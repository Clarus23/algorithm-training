#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(int i=0; i<=d; i+=k)
        answer += (int)(sqrt((long long)(d-i)*(d+i))/k)+1;
    
    return answer;
}