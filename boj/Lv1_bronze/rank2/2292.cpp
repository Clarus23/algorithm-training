#include <iostream>
using namespace std;

int main(void) {
    int target;
    cin >> target;

    int a=1; int cnt=1;
    while(a < target) {
        a += cnt*6;
        cnt++;
    }
    cout << cnt;

    return 0;
}