#include <iostream>
using namespace std;

#define MODULAR 1000000007;

long long calculateModInverse(int x) {
    long long inverse = 1;
    long long cur = x;
    int power = 1000000005;

    while(power) {
        if(power%2) inverse = (inverse*cur)%MODULAR;
        cur = (cur*cur)%MODULAR;
        power/=2;
    }

    return inverse%MODULAR;
}

int gcd(int a, int b) {
    pair<int, int> maxMin = (a>b) ? make_pair(a, b) : make_pair(b, a);

    while(maxMin.second) {
        int temp = maxMin.first % maxMin.second;
        maxMin.first = maxMin.second;
        maxMin.second = temp;
    }

    return maxMin.first;
}

int main() {
    int dice; scanf("%d", &dice);
    int answer = 0;
    while(dice--) {
        int n, s; scanf("%d %d", &n, &s);
        int gcdValue = gcd(n, s);

        n /= gcdValue;
        s /= gcdValue;

        answer += (s * calculateModInverse(n))%MODULAR;
        answer %= MODULAR;
    }

    printf("%d", answer);

    return 0;
}