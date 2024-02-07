#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    const long long r2S = (long long)r2*r2;
    const long long r1S = (long long)r1*r1;
    long long answer = 1;
    
    for(int x=1; x<r1; x++)
        answer += ((int)sqrt(r2S-(long long)x*x) - ceil(sqrt(r1S-(long long)x*x)) + 1);
    
    for(int x=r1; x<r2; x++)
        answer += ((int)sqrt(r2S-(long long)x*x) + 1);
    
    answer *= 4;
    
    return answer;
}