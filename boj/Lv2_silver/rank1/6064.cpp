#include <iostream>
using namespace std;

int lcm(int a, int b) {
    int max = (a>b)?a:b;
    int min = (a<b)?a:b;

    int temp;
    while(min) {
        temp = min;
        min = max%min;
        max = temp;
    }

    return ((a/max)*b);
}

int main(void) {
    int testCase;
    cin >> testCase;

    for(int i=0; i<testCase; i++) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        bool isValid=false;
        int maxYear = lcm(m, n);
        for(int year=x; year<=maxYear; year+=m) {
            if(!((year-y)%n)) {
                cout << year << '\n';
                isValid=true;
                break;
            }
        }

        if(!isValid) cout << -1 << '\n';
    }

    return 0;
}