#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int a, b, c, hypotenuse;
    while(true) {
        cin >> a >> b >> c;
        if(!a && !b && !c) break;

        hypotenuse = max({a, b, c});
        if((a*a + b*b + c*c) == 2*hypotenuse*hypotenuse) cout << "right\n";
        else cout << "wrong\n";
    }
    return 0;
}