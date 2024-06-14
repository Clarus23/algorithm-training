#include <iostream>
using namespace std;

int main(void) {
    bool mod[42] = {false, };
    int n;
    int cnt=0;
    for(int i=0; i<10; i++) {
        cin >> n;
        if(!mod[n%42]) {
            mod[n%42] = true;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}