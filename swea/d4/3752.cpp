#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for(int testCase=1; testCase<=t; testCase++) {
        int n; cin >> n;

        vector<bool> isPossible(10001, false);
        vector<int> scores(1, 0);
        isPossible[0] = true;
        for(int i=0; i<n; i++) {
            int point; cin >> point;

            vector<int> newScores(scores.size());
            int top = -1;
            for(int it : scores) {
                if(isPossible[it+point]) continue;

                newScores[++top] = it+point;
                isPossible[it+point] = true;
            }

            for(; top>=0; top--)
                scores.push_back(newScores[top]);
        }

        cout << '#' << testCase << ' ' << scores.size() << '\n';
    }

    return 0;
}