#include <iostream>
using namespace std;

int main(void) {
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;

    int math = (a%c) ? (a/c+1) : (a/c);
    int korean = (b%d) ? (b/d+1) : (b/d);
    int max = (math > korean) ? math : korean;
    cout << l-max;
    return 0;
}