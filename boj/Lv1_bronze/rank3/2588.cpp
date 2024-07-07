#include <iostream>
using namespace std;

int main(void) {
    int n1, n2;
    cin >> n1 >> n2;

    int sum=0, weight=1;
    while(n2) {
        cout << n1*(n2%10) << '\n';
        sum += (weight*n1*(n2%10));
        n2/=10;
        weight*=10;
    } cout << sum;

    return 0;
}