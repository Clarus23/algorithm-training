#include <iostream>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    int factorial[11] = {1, };
    for(int i=1; i<11; i++) factorial[i] = i*factorial[i-1];

    cout << factorial[n]/factorial[k]/factorial[n-k];

    return 0;
}