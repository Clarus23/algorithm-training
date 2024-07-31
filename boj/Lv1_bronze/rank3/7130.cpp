#include <iostream>
using namespace std;

int main(void) {
    int m, h, n;
    scanf("%d %d\n%d", &m, &h, &n);
    int answer = 0;
    while(n--) {
        int c, b;
        scanf("%d %d", &c, &b);
        answer += (m*c > h*b) ? m*c : h*b;
    } printf("%d", answer);

    return 0;
}