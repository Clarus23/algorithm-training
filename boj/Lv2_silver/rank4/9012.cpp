#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int t; cin >> t;

    string ps;
    for(int i=0; i<t; i++) {
        cin >> ps;

        vector<char> stack;
        bool isVps = true;
        for(char c : ps) {
            if(c == '(') stack.push_back(c);
            else if(!stack.empty()) stack.pop_back();
            else {
                isVps = false;
                break;
            }
        } if(!stack.empty()) isVps = false;

        if(isVps) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}