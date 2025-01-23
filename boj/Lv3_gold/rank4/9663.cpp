#include <iostream>
#include <vector>
using namespace std;

bool isPossible(const vector<int>& qPos, const int& top) {
    for(int i=0; i<top; i++) {
        if(qPos[top] == qPos[i]) return false;
        if(top-i == abs(qPos[top]-qPos[i])) return false;
    }

    return true;
}

void backTracking(vector<int>& qPos, int top, const int& n, int& answer) {
    if(top == n-1) {
        answer++;
        return;
    }

    for(int i=0; i<n; i++) {
        qPos[++top] = i;

        if(isPossible(qPos, top))
            backTracking(qPos, top, n, answer);

        top--;
    }
}

int main() {
    int n; scanf("%d", &n);

    int answer = 0;

    vector<int> qPos(n);
    int top = -1;
    backTracking(qPos, top, n, answer);

    printf("%d", answer);

    return 0;
}