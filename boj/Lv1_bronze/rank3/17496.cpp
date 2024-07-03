#include <iostream>
using namespace std;

int main(void) {
    int n, t, c, p;
    cin >> n >> t >> c >> p;
    cout << p*c*((n-1)/t);
    return 0;
}