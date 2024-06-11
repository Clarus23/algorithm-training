#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    do {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        reverse(arr.begin()+m, arr.end());
    } while(next_permutation(arr.begin(), arr.end()));

    return 0;
}