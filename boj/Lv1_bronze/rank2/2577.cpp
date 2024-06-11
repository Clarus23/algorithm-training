#include <iostream>
using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;

    int digit[10] = {0, };
    string number = to_string(a*b*c);
    for(char c : number) digit[c-'0']++;

    for(int i=0; i<10; i++) cout << digit[i] << '\n';

    return 0;
}