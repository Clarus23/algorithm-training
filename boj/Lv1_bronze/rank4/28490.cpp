#include <iostream>
using namespace std;

int main(void) {
    int n; cin >> n;
    int h, w, max=0;
    while(n--) {
        cin >> h >> w;
        max = (h*w > max) ? h*w : max;
    } cout << max;
    return 0;
}