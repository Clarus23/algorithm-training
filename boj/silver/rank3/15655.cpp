#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<bool> flag(n, false);
    for(int i=0; i<m; i++) flag[i] = true;

    sort(arr.begin(), arr.end());

    do {
        for(int i=0; i<n; i++) if(flag[i]) cout << arr[i] << ' ';
        cout << '\n';
    } while(prev_permutation(flag.begin(), flag.end()));

    return 0;
}