#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    pair<int, string> *members = new pair<int, string>[n];
    for(int i=0; i<n; i++) cin >> members[i].first >> members[i].second;
    stable_sort(members, members+n, [](pair<int, string> a, pair<int, string> b) {
        return (a.first < b.first);
    });

    for(int i=0; i<n; i++) cout << members[i].first << ' ' << members[i].second << '\n';

    delete []members;
    return 0;
}