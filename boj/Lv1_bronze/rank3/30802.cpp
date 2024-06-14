#include <iostream>
using namespace std;

int main(void) {
    int n, t, p;
    int tSize[6] = {0, };

    cin >> n;
    for(int i=0; i<6; i++) cin >> tSize[i];
    cin >> t >> p;

    int tBundle = 0;
    for(int size : tSize) {
        if(size%t) tBundle += (size/t+1);
        else tBundle += (size/t);
    }

    cout << tBundle << '\n' << n/p << ' ' << n%p;

    return 0;
}