#include <iostream>
using namespace std;

int main(void) {
    int a, b, v;
    cin >> a >> b >> v;

    v -= a;
    a -= b;

    int answer = (v%a) ? (v/a+1) : (v/a);
    cout << answer+1;

    return 0;
}