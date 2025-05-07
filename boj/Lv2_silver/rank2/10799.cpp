#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string iron; cin >> iron;

    int answer = 0;

    int top = -1;
    for(int i=0; i<iron.size(); i++) {
        if(iron[i] == '(') ++top;
        else if(iron[i-1] == '(') answer += top--;
        else {
            answer++;
            top--;
        }
    }

    cout << answer;

    return 0;
}