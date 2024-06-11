#include <iostream>
using namespace std;

int main(void) {
    int sn[5];
    for(int i=0; i<5; i++) cin >> sn[i];

    int validation = 0;
    for(int i=0; i<5; i++) validation += (sn[i]*sn[i]);
    validation %= 10;

    cout << validation;

    return 0;
}