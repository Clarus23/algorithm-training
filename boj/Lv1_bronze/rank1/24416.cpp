#include <iostream>
using namespace std;

int main(void) {
    int n; scanf("%d", &n);
    int *fibo = new int[n];
    fibo[0] = 1; fibo[1] = 1;
    for(int i=2; i<n; i++) fibo[i] = fibo[i-1] + fibo[i-2];

    printf("%d %d", fibo[n-1], n-2);

    delete []fibo;
    return 0;
}