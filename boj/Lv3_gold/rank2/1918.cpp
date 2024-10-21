#include <iostream>
using namespace std;

int main() {
    string infix; cin >> infix;

    char stack[100] = {'\0', };
    int stackTop = -1;
    for(char& c : infix) {
        switch(c) {
            case '(':
                stack[++stackTop] = c;
                break;
            case ')':
                while(stackTop > -1) {
                    if(stack[stackTop] == '(') {
                        stackTop--; break;
                    }
                    printf("%c", stack[stackTop--]);
                }
                break;
            case '+': case '-':
                while(stackTop > -1) {
                    if(stack[stackTop] == '(') break;
                    printf("%c", stack[stackTop--]);
                }
                stack[++stackTop] = c;
                break;
            case '*': case '/':
                while(stackTop > -1) {
                    if(stack[stackTop] == '(' || stack[stackTop] == '+' || stack[stackTop] == '-') break;
                    printf("%c", stack[stackTop--]);
                }
                stack[++stackTop] = c;
                break;
            default:
                printf("%c", c);
        }
    } while(stackTop > -1) printf("%c", stack[stackTop--]);

    return 0;
}