#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<bool> flag(n, false);
    for(int i=0; i<m; i++) flag[i] = true;

    do {
        for(int i=0; i<n; i++) if(flag[i]) cout << i+1 << ' ';
        cout << '\n';
    } while(prev_permutation(flag.begin(), flag.end()));

    return 0;
}