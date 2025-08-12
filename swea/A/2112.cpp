#include <iostream>
#include <vector>
using namespace std;

int d, w, k;
int minInjection;
// 0->A처리, 1->B처리, 2->약품X
int status[3] = {0, };

void dfs(vector<int>& film, int depth, int injection
    , vector<int> prevContinue, vector<int> prevMaxContinue) {

    if (depth == d) {
        for (int max : prevMaxContinue) if (max < k) return;

        minInjection = (injection < minInjection) ? injection : minInjection;
        return;
    }
    if (injection >= minInjection) return;

    vector<int> curContinue(w);
    vector<int> curMaxContinue(w);

    status[2] = film[depth];
    for (int i=2; i>=0; --i) {
        int check = film[depth-1] ^ status[i];

        for (int j=0; j<w; ++j) {
            if ((check & (1 << j)) == 0) {
                curContinue[j] = prevContinue[j]+1;
                curMaxContinue[j] = (curContinue[j] > prevMaxContinue[j]) ? curContinue[j] : prevMaxContinue[j];
            } else {
                curContinue[j] = 1;
                curMaxContinue[j] = prevMaxContinue[j];
            }
        }
        int backup = film[depth];
        film[depth] = status[i];
        dfs(film, depth+1, injection+((i==2)?0:1), curContinue, curMaxContinue);
        film[depth] = backup;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc; cin >> tc;
    for (int t=1; t<=tc; ++t) {
        cin >> d >> w >> k;

        vector<int> film(d);
        for (int i=0; i<d; ++i) {
            for (int j=0; j<w; ++j) {
                int temp; cin >> temp;
                film[i] |= (temp << j);
            }
        }
        status[1] = (1<<w) - 1;
        minInjection = k;
        vector<int> prevContinue(w, 1);
        vector<int> prevMaxContinue(w, 1);

        dfs(film, 1, 0, prevContinue, prevMaxContinue);
        film[0] = status[0];
        dfs(film, 1, 1, prevContinue, prevMaxContinue);
        film[0] = status[1];
        dfs(film, 1, 1, prevContinue, prevMaxContinue);

        cout << "#" << t << " " << minInjection << "\n";
    }

    return 0;
}