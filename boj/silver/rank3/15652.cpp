#include <iostream>
#include <vector>
using namespace std;

void duplicateCombination(vector<int> &arr, int &m, int &n, int cnt, int start) {
    if(cnt == m) {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = start; i<=n; i++) {
        arr[cnt] = i;
        duplicateCombination(arr, m, n, cnt+1, i);
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> arr(m, 0);
    duplicateCombination(arr, m, n, 0, 1);

    return 0;
}