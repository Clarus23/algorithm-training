#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    for(int i : v) if(i < x) cout << i << ' ';

    return 0;
}