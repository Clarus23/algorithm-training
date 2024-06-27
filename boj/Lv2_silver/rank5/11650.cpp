#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n; cin >> n;
    pair<int, int>* points = new pair<int, int>[n];
    for(int i=0; i<n; i++) cin >> points[i].first >> points[i].second;

    sort(points, points+n, [](pair<int, int>& a, pair<int, int>& b) {
        return (a.first < b.first || (a.first == b.first && a.second < b.second));
    });

    for(int i=0; i<n; i++) cout << points[i].first << ' ' << points[i].second << '\n';

    delete []points;
    return 0;
}