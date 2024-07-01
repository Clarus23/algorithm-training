#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string str;
    int top;
    char* stack = new char[100];
    while(true) {
        getline(cin, str);
        if(str == ".") break;

        top=-1; bool isBalanced = true;
        for(char c : str) {
            if(c == '(' || c == '[') stack[++top] = c;
            else if(c == ')' || c == ']') {
                char out = stack[top--];
                if((c == ')' && out == '(') || (c == ']' && out == '[')) continue;

                isBalanced = false;
                break;
            } else continue;
        } if(top != -1) isBalanced = false;

        if(isBalanced) cout << "yes\n";
        else cout << "no\n";
    }

    delete []stack;
    return 0;
}