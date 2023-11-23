#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    // f(n) = f(n-1) + f(n-2) 즉, 피보나치수열.
    vector<int> fiboMod(2, 1); // f(0) = 1, f(1) = 1
    for(int i=2; i<=n; i++) fiboMod.push_back((fiboMod[i-1] + fiboMod[i-2])%1000000007);

    return fiboMod[n];
}