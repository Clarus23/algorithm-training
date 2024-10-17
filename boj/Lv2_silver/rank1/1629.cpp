#include <iostream>
#include <map>
using namespace std;

int myMul(map<int, int>& memo, int a, int b, int c) {
    if(b == 1) return a%c;
    if(memo.find(b) != memo.end()) return memo[b];

    int temp;
    if(b%2) temp = ((long long)myMul(memo, a, b/2, c)%c * (long long)myMul(memo, a, b/2+1, c)%c)%c;
    else temp = ((long long)myMul(memo, a, b/2, c)%c * (long long)myMul(memo, a, b/2, c)%c)%c;

    memo.insert({b, temp});
    return temp;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    map<int, int> memo;
    printf("%d", myMul(memo, a, b, c));
    return 0;
}