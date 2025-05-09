#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int tc=0; tc<10; tc++) {
        int n; cin >> n;
        vector<int> buildings(n, 0);
        for(int i=0; i<n; i++) cin >> buildings[i];

        int count=0;
        for(int i=2; i<n-2; i++) {
            int leftMax = (buildings[i-2] > buildings[i-1]) ? buildings[i-2] : buildings[i-1];
            int rightMax = (buildings[i+2] > buildings[i+1]) ? buildings[i+2] : buildings[i+1];

            int max = (leftMax > rightMax) ? leftMax : rightMax;

            count += (buildings[i]-max > 0) ? buildings[i]-max : 0;
        }

        cout << "#" << tc+1 << ' ' << count << '\n';
    }

    return 0;
}NsYPj9lu