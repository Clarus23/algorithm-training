#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    int bag5=n/5;
    n %= 5;

    bag5 -= (n%3);
    int bag3 = n/3+2*(n%3);

    if(bag5 < 0) cout << -1;
    else cout << bag3+bag5;

    return 0;
}