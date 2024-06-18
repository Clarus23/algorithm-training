#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n;

    while(true) {
        cin >> n;
        if(!n) break;

        string strN = to_string(n);
        string reverseN = strN;
        reverse(reverseN.begin(), reverseN.end());

        if(strN == reverseN) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}