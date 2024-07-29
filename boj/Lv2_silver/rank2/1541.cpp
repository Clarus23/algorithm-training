#include <iostream>
using namespace std;

int main(void) {
    string str; cin >> str;
    int answer = 0, cur = 0;
    bool isPlus = true;
    for(char c : str) {
        if(c == '+' || c == '-') {
            answer += ((isPlus) ? cur : -cur);

            if(c == '-') isPlus = false;
            cur = 0;
        } else {
            cur *= 10;
            cur += (c-'0');
        }
    } answer += ((isPlus) ? cur : -cur);
    cout << answer;

    return 0;
}