#include <iostream>
using namespace std;

int main(void) {
    int n; scanf("%d", &n);
    int* target = new int[n];
    for(int i=0; i<n; i++) scanf("%d", target+i);

    int stackTop=-1, opsTop=-1, cur=0;
    int* stack = new int[n];
    char* ops = new char[2*n];
    for(int i=1; i<=n; i++) {
        stack[++stackTop] = i;
        ops[++opsTop] = '+';

        while(stackTop != -1 && stack[stackTop] == target[cur]) {
            cur++;
            stackTop--;
            ops[++opsTop] = '-';
        }
    }

    if(stackTop != -1) printf("NO");
    else for(int i=0; i<2*n; i++) printf("%c\n", ops[i]);

    delete []target;
    delete []stack;
    delete []ops;
    return 0;
}