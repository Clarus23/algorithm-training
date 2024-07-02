#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n, p;
    cin >> n >> p;

    int coupon[4] = {500, p/10, 2000, p/4};
    if(n>=20) p -= *max_element(coupon, coupon+4);
    else if(n>=15) p -= *max_element(coupon, coupon+3);
    else if(n>=10) p -= *max_element(coupon, coupon+2);
    else if(n>=5) p -= 500;

    cout << ((p<0) ? 0 : p);

    return 0;
}