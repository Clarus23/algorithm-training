#include <iostream>
using namespace std;

int main(void) {
    int testCase;
    cin >> testCase;

    for(int test=0; test<testCase; test++) {
        string s;
        int r;
        cin >> r >> s;

        for(char c : s) for(int i=0; i<r; i++) cout << c;
        cout << '\n';
    }
    return 0;
}