#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase; cin >> testCase;
    while(testCase--) {
        string s; cin >> s;
        int op = 0;

        int front = 0;
        int rear = (int)s.size()-1;
        while(front <= rear) {
            if(s[front] == s[rear]) {
                ++front;
                --rear;
            } else if(s[front] == 'x') {
                ++op;
                ++front;
            } else if(s[rear] == 'x') {
                ++op;
                --rear;
            } else {
                op = -1;
                break;
            }
        }

        cout << op << '\n';
    }

    return 0;
}