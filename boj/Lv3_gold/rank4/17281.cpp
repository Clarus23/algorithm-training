#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> scoreBoard(n, vector<int>(9));
    for(auto& i : scoreBoard) for(int& j : i) cin >> j;

    // 0번 선수는 무조건 4번 타자
    int lineup[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int maxScore = 0;
    do {
        int score = 0; int batter = 0;
        for(int innings=0; innings < n; innings++) {
            bool base[4] = {true, false, false, false};
            int out = 0;
            while(out < 3) {
                int curBatter;
                if(batter >= 0 && batter < 3) curBatter = lineup[batter];
                else if(batter == 3) curBatter = 0;
                else curBatter = lineup[batter-1];

                int batting = scoreBoard[innings][curBatter];
                if(batting == 0) out++;
                else {
                    for(int i=(4-batting); i<4; i++) score += (base[i]) ? 1 : 0;
                    for(int i=3; i>(batting-1); i--) base[i] = base[i-batting];
                    for(int i=1; i<batting; i++) base[i] = false;
                }

                batter = (++batter%9);
            }
        }

        maxScore = (score > maxScore) ? score : maxScore;
    } while(next_permutation(lineup, lineup+8));

    cout << maxScore;

    return 0;
}