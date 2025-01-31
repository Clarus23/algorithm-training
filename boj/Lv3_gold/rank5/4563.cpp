#include <iostream>
using namespace std;

int revengePytagoras(int a) {
    int cnt=0;
    long long squareA = (long long)a*a;
    for(int i=1; i<a; i++) {
        if(squareA%i) continue;

        long long x = squareA/i;
        if(!((x+i)%2) && !((x-i)%2) && (x-i) > 2*a) cnt++;
    }

    return cnt;
}

int main() {
    while(true) {
        int a; scanf("%d", &a);
        if(!a) break;

        printf("%d\n", revengePytagoras(a));
    }

    return 0;
}