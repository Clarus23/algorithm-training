#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    vector<int> v(9, 0);
    for(int i=0; i<9; i++) cin >> v[i];

    cout << *max_element(v.begin(), v.end()) << '\n' << max_element(v.begin(), v.end())-v.begin()+1;
    return 0;
}