#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int a=1, b=0;
    // n을 연속된 자연수로 표현하기 위한 방법 => `n = a*x + b` 식의 x가 자연수이면 됨.
    // 단, a는 초기값 1, 차이가 1인 등차수열, b는 초기값 0, 차이가 a인 수열.
    // x = (n-b)/a 로 표현이 가능하고, x가 자연수이기 위해서는 (n-b)%a 가 0이어야함.
    while(b<n) {
        if(!((n-b)%a)) answer++;
        
        b += a;
        a += 1;
    }
    
    
    return answer;
}