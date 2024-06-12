#include <cstdio>
using namespace std;

int main(void) {
    long long g[1000001] = {0, };
    for(int i=1; i<1000001; i++)
        for(int j=i; j<1000001; j+=i) g[j]+=i;
    for(int i=2; i<1000001; i++) g[i] += g[i-1];

    int testCase, n;
    scanf("%d", &testCase);
    for(int i=0; i<testCase; i++) {
        scanf("%d", &n);
        printf("%lld\n", g[n]);
    }

    return 0;
}