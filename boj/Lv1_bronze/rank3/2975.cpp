#include <iostream>

int main(void) {
    int cur, diff;
    char op;
    while(true) {
        scanf("%d %c %d", &cur, &op, &diff);
        if(!cur && op=='W' && !diff) break;

        if(op == 'W') {
            if(cur-diff < -200) printf("Not allowed\n");
            else printf("%d\n", cur-diff);
        } else printf("%d\n", cur+diff);
    }

    return 0;
}