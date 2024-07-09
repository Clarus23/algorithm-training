#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n; scanf("%d", &n);
    int* p = new int[n];
    for(int i=0; i<n; i++) scanf("%d", p+i);
    sort(p, p+n);

    int sum=0;
    for(int i=0; i<n; i++) sum += (p[i]*(n-i));
    printf("%d", sum);

    delete []p;
    return 0;
}