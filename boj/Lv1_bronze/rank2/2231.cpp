#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    bool isPossible = false;
    int candidate, temp;
    for(int i=1; i<=n; i++) {
        candidate = i;
        temp = i;
        while(temp) {
            candidate += (temp%10);
            temp /= 10;
        }

        if(candidate == n) {
            cout << i;
            isPossible = true;
            break;
        }
    }

    if(!isPossible) cout << 0;

    return 0;
}