#include <cstdio>
using namespace std;

int main(void) {
    int k; scanf("%d", &k);

    int* accountBook = new int[k];
    int top=-1; unsigned int sum=0;
    int money;
    while(k--) {
        scanf("%d", &money);
        if(money) {
            accountBook[++top] = money;
            sum += money;
        } else sum -= accountBook[top--];
    }

    printf("%d", sum);

    delete []accountBook;
    return 0;
}