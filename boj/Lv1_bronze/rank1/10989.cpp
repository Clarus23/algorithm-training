#include <cstdio>
using namespace std;

int main(void) {
    int numbers[10001] = {0, };
    int n;
    scanf("%d", &n);

    int num;
    for(int i=0; i<n; i++) {
        scanf("%d", &num);
        numbers[num]++;
    }

    for(int i=1; i<=10000; i++) {
        if(!numbers[i]) continue;
        for(int j=numbers[i]; j>0; j--) printf("%d\n", i);
    }

    return 0;
}