#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    int cnt=0, id=5;
    while(id <= n) {
        cnt += n/id;
        id *= 5;
    }

    cout << cnt;

    return 0;
}