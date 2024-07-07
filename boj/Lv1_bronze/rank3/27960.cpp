#include <iostream>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    int c=0;
    for(int i=1; i<1024; i*=2) {
        if(a%2 != b%2) c+=i;
        a/=2; b/=2;
    } cout << c;

    return 0;
}