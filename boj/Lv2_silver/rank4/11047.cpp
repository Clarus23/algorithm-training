#include <iostream>
using namespace std;

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int id;
    int* coins = new int[n];
    for(int i=0; i<n; i++) {
        scanf("%d", coins+i);
        if(coins[i] <= k) id = i;
    }

    int cnt=0;
    for(int i=id; i>0; i--) {
        cnt += (k/coins[i]);
        k %= coins[i];
        if(!k) break;
    } cnt += k;
    printf("%d", cnt);

    delete []coins;
    return 0;
}