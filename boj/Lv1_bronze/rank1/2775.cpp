#include <iostream>
using namespace std;

int main(void) {
    int apartment[15][14] = {0, };
    for(int i=0; i<14; i++) apartment[0][i] = (i+1);

    for(int i=1; i<15; i++) {
        for(int j=0; j<14; j++) {
            apartment[i][j] = 0;
            for(int k=0; k<=j; k++) apartment[i][j] += apartment[i-1][k];
        }
    }

    int t;
    cin >> t;

    int k, n;
    for(int i=0; i<t; i++) {
        cin >> k >> n;
        cout << apartment[k][n-1] << '\n';
    }
    return 0;
}