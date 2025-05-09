#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int* towers = new int[n];
    for(int i=0; i<n; i++) cin >> towers[i];

    auto* stack = new pair<int, int>[n];
    int top = -1;
    stack[++top] = {n-1, towers[n-1]};

    int* answer = new int[n];
    for(int i=n-2; i>=0; i--) {
        while(top != -1 && towers[i] > stack[top].second)
            answer[stack[top--].first] = i+1;

        stack[++top] = {i, towers[i]};
    } while(top != -1) answer[stack[top--].first] = 0;

    for(int i=0; i<n; i++) cout << answer[i] << ' ';

    delete[] answer;
    delete[] stack;
    delete[] towers;

    return 0;
}