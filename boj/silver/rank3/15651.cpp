#include <iostream>
#include <vector>
using namespace std;

void duplicatePermutation(vector<int> &arr, int cnt, int &n, int &m) {
    if(cnt == m) {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=1; i<=n; i++) {
        arr[cnt] = i;
        duplicatePermutation(arr, cnt+1, n, m);
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> arr(m, 0);
    duplicatePermutation(arr, 0, n, m);

    return 0;
}