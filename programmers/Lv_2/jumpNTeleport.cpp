#include <iostream>
using namespace std;

int solution(int n) {
    int ans = 0;
    
    while(true) {
        if(n == 1) {
            ans++; break;
        } else if(n%2) {
            n = (n-1)/2;
            ans++;
        } else n /= 2;
    }

    return ans;
}