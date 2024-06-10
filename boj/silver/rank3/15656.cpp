#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void duplicatePermutation(vector<int> &arr, vector<int> & v, int &n, int &m, int cnt) {
    if(cnt == m) {
        for(int i=0; i<m; i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=0; i<n; i++) {
        v[cnt] = arr[i];
        duplicatePermutation(arr, v, n, m, cnt+1);
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    vector<int> v(n, 0);
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    duplicatePermutation(arr, v, n, m, 0);

    return 0;
}