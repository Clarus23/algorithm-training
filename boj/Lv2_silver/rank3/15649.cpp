#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; i++) v[i] = i+1;

    do {
        for(int i=0; i<m; i++) cout << v[i] << ' ';
        cout << '\n';
        reverse(v.begin()+m, v.end());
    } while(next_permutation(v.begin(), v.end()));

    return 0;
}