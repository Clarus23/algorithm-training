#include <iostream>

int main(void) {
    int n; scanf("%d", &n);
    int* fibo = new int[n+1];
    fibo[0] = 1; fibo[1] = 1;

    for(int i=2; i<=n; i++) fibo[i] = (fibo[i-1] + fibo[i-2])%10007;
    printf("%d", fibo[n]);

    delete []fibo;
    return 0;
}