#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> ability(n, vector<int>(n,0));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> ability[i][j];

    int minDiff = INT_MAX;
    vector<bool> flag(n, false);
    for(int i=0; i<n/2; i++) flag[i] = true;
    do {
        vector<int> start;
        vector<int> link;

        int diff=0;
        for(int i=0; i<n; i++) {
            if(flag[i]) {
                for(int team : start) diff += (ability[i][team] + ability[team][i]);
                start.push_back(i);
            } else {
                for(int team : link) diff -= (ability[i][team] + ability[team][i]);
                link.push_back(i);
            }
        }

        minDiff = min(minDiff, abs(diff));
    } while(prev_permutation(flag.begin(), flag.end()));

    cout << minDiff;

    return 0;
}