#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MIN -1000000000
#define MAX 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> op(4);
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    for(int i=0; i<4; i++) cin >> op[i];


    int min = MAX;
    int max = MIN;

    queue<pair<pair<vector<int>, int>, int>> q;
    q.push({{op, a[0]}, 0});
    while(!q.empty()) {
        vector<int> op = q.front().first.first;
        int result = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        if(depth == n-1) {
            min = (result < min) ? result : min;
            max = (result > max) ? result : max;

            continue;
        }

        for(int i=0; i<4; i++) {
            if(op[i] == 0) continue;

            vector<int> nextOp = op;
            nextOp[i]--;

            if(i == 0) q.push({{nextOp, result+a[depth+1]}, depth+1});
            else if(i == 1) q.push({{nextOp, result-a[depth+1]}, depth+1});
            else if(i == 2) q.push({{nextOp, result*a[depth+1]}, depth+1});
            else q.push({{nextOp, result/a[depth+1]}, depth+1});
        }
    }

    cout << max << '\n' << min;

    return 0;
}