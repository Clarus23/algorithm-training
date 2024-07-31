#include <iostream>
using namespace std;

int main(void) {
    int h; cin >> h;

    if(h == 0) cout << 1;
    else if(h == 1) cout << 0;
    else {
        string answer = (h%2) ? "4" : "";
        for(int i=0; i<h/2; i++) answer += "8";
        cout << answer;
    }

    return 0;
}