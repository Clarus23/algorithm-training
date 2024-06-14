#include <iostream>
using namespace std;

int main(void) {
    int testCase;
    cin >> testCase;

    for(int t=0; t<testCase; t++) {
        string oxSheet;
        cin >> oxSheet;

        int point=0;
        int curPoint=0;
        for(char c : oxSheet) {
            if(c=='O') {
                curPoint++;
                point += curPoint;
            } else curPoint=0;
        }

        cout << point << '\n';
    }

    return 0;
}