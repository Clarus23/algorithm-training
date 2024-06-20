#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    int *stack = new int[n];
    int top = -1;
    string cmd; int element;
    for(int i=0; i<n; i++) {
        cin >> cmd;
        if(cmd == "push") {
            scanf("%d", &element);
            stack[++top] = element;
        } else if(cmd == "pop") {
            if(top == -1) printf("-1\n");
            else printf("%d\n", stack[top--]);
        } else if(cmd == "top") {
            if(top == -1) printf("-1\n");
            else printf("%d\n", stack[top]);
        }
        else if(cmd == "size") printf("%d\n", top+1);
        else if(cmd == "empty") printf("%d\n", (top==-1));
    }
    delete []stack;

    return 0;
}