#include <cstdio>
using namespace std;

int main(void) {
    int testCase;
    scanf("%d", &testCase);

    for(int t=0; t<testCase; t++) {
        int h, w, n;
        scanf("%d %d %d", &h, &w, &n);
        n--;

        printf("%d%02d\n", (n%h+1), (n/h+1));
    }

    return 0;
}