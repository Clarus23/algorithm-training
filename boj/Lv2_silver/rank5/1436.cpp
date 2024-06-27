#include <iostream>
using namespace std;

int main(void) {
    int n; cin >> n;
    int title=0;
    for(int i=666;; i++) {
        if(to_string(i).find("666") == string::npos) continue;

        title++;
        if(title == n) {
            cout << i;
            break;
        }
    }
    return 0;
}