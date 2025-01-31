#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; scanf("%d", &n);

    vector<pair<int, int>> coord(n);
    for(int i=0; i<n; i++)
        scanf("%d %d", &coord[i].first, &coord[i].second);

    double area = 0L;
    for(int i=0; i<n; i++) {
        area += (double)coord[i].first * coord[(i+1)%n].second;
        area -= (double)coord[i].second * coord[(i+1)%n].first;
    } area /= 2;

    printf("%.1lf", abs(area));

    return 0;
}