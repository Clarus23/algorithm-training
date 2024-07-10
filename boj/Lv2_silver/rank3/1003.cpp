#include <iostream>
using namespace std;

pair<int, int> operator +(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first+b.first, a.second+b.second};
}

int main(void) {
    pair<int, int> zeroOne[41] = {{1, 0}, {0, 1}, }; // {0의 개수, 1의 개수}
    for(int i=2; i<41; i++) zeroOne[i] = zeroOne[i-1] + zeroOne[i-2];

    int t; scanf("%d", &t);
    int n;
    while(t--) {
        scanf("%d", &n);
        printf("%d %d\n", zeroOne[n].first, zeroOne[n].second);
    }
    return 0;
}