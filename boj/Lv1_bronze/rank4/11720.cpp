#include <iostream>
using namespace std;

int main(void) {
    int n;
    string s;
    cin >> n >> s;

    int sum=0;
    for(char c : s) sum += (c-'0');

    cout << sum;

    return 0;
}