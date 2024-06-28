#include <cstdio>
using namespace std;

int main(void) {
    int m; scanf("%d", &m);

    long long int sum=0, xorSum=0;
    int op, element;
    while(m--) {
        scanf("%d", &op);
        if(op==1) {
            scanf("%d", &element);
            sum += element;
            xorSum ^= element;
        }
        if(op==2) {
            scanf("%d", &element);
            sum -= element;
            xorSum ^= element;
        }
        else if(op==3) printf("%lld\n", sum);
        else if(op==4) printf("%lld\n", xorSum);
    }

    return 0;
}