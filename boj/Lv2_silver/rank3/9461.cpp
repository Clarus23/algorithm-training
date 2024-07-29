#include <iostream>
using namespace std;

int main(void) {
    long long int pNum[100] = {1, 1, 1, 2, 2, };
    for(int i=5; i<100; i++) pNum[i] = pNum[i-1] + pNum[i-5];

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        printf("%lld\n", pNum[n-1]);
    }

    return 0;
}