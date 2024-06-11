#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void duplicateCombination(vector<int> &arr, vector<int>& v, int &n, int &m, int cnt, int num) {
    if(cnt == m) {
        for(int i=0; i<m; i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=num; i<n; i++) {
        v[cnt] = arr[i];
        duplicateCombination(arr, v, n, m, cnt+1, i);
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> v(m, 0);

    sort(arr.begin(), arr.end());
    duplicateCombination(arr, v, n, m, 0, 0);

    return 0;
}