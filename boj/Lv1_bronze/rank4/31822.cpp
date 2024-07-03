#include <iostream>
using namespace std;

int main(void) {
    string target, subject;
    int n, cnt=0;
    cin >> target >> n;
    target = target.substr(0, 5);
    while(n--) {
        cin >> subject;
        if(target == subject.substr(0, 5)) cnt++;
    } cout << cnt;
    return 0;
}