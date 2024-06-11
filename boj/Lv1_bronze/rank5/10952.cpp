#include <iostream>
using namespace std;

int main(void) {
    int a, b;
    while(true) {
        cin >> a >> b;
        if(!a && !b) break;

        cout << a+b << '\n';
    }

    return 0;
}