#include <string>
#include <vector>

using namespace std;

//에라토스테네스의 체 이용해 소수값 구하기.
int solution(int n) {
    int answer = 0;
    vector<bool> prime(n+1, true);
    for(int i=2; i<=n; i++) {
        if(!prime[i]) continue;
        for(int j=2*i; j<=n; j+=i) {
            prime[j] = false;
        }
    }
    for(int i=2; i<=n; i++) {
        if(prime[i]) answer++;
    }
    
    return answer;
}