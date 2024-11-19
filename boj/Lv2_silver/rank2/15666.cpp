#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rCombView(vector<int>& arr, vector<int>& answer, int top, int n) {
    if(top == answer.size()) {
        for(int num : answer) printf("%d ", num);
        printf("\n");
        return;
    }

    for(int i=n; i<arr.size(); i++) {
        answer[top] = arr[i];
        rCombView(arr, answer, top+1, i);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> arr(n, 0);
    for(int& num : arr) scanf("%d", &num);
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> answer(m, 0);
    rCombView(arr, answer, 0, 0);

    return 0;
}