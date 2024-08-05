#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    int n; scanf("%d", &n);
    map<long long, int> m;
    vector<long long> arr(n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
        m[arr[i]] = 0;
    }

    int cnt=0;
    for(auto it=m.begin(); it!=m.end(); it++, cnt++) it->second = cnt;
    for(int i=0; i<n; i++) printf("%d ", m[arr[i]]);

    return 0;
}