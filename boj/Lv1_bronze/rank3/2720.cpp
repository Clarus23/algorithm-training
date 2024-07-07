#include <iostream>
using namespace std;

int main(void) {
    int t; cin >> t;
    int c;
    while(t--) {
        cin >> c;
        cout << c/25 << ' ' << (c%25)/10 << ' ' << ((c%25)%10)/5 << ' ' << c%5 << '\n';
    }

    return 0;
}