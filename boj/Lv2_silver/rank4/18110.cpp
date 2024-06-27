#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n; cin >> n;
    if(!n) {
        cout << 0;
        return 0;
    }

    int* difficulty = new int[n];
    for(int i=0; i<n; i++) cin >> difficulty[i];
    sort(difficulty, difficulty+n);

    int avg = 0;
    int except = ((double)n/100)*15 + 0.5;
    for(int i=except; i<n-except; i++) avg += difficulty[i];

    cout << (int)((double)avg/(n-2*except) + 0.5);

    delete []difficulty;
    return 0;
}