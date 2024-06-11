#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<char> op(n);
    for(int i=0; i<n; i++) cin >> op[i];
    vector<char> digit = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    string maxVal = to_string(LONG_LONG_MIN), minVal = to_string(LONG_LONG_MAX);
    do {
        bool isPossible = true;
        string cur="";
        for(int i=0; i<=n; i++) {
            if((op[i]=='>' && digit[i]<digit[i+1]) || (op[i]=='<' && digit[i]>digit[i+1])) {
                isPossible = false;
                break;
            }
            cur += digit[i];
        } reverse(digit.begin()+n+1, digit.end());
        if(!isPossible) continue;

        maxVal = max(maxVal, cur);
        minVal = min(minVal, cur);
    } while(next_permutation(digit.begin(), digit.end()));

    cout << maxVal << '\n' << minVal;

    return 0;
}