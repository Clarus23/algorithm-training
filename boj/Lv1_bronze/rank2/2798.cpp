#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<bool>& selected, vector<int>& cards, int idx, int depth, int& target, int& candidate, int sum) {
    if(depth == 3) {
        candidate = (sum > candidate) ? sum : candidate;
        return;
    }

    for(int i=idx; i<cards.size(); i++) {
        if(selected[i]) continue;
        if(sum + cards[i] > target) continue;

        sum += cards[i];
        selected[i] = true;
        dfs(selected, cards, i, depth+1, target, candidate, sum);
        if(candidate == target) return;

        sum -= cards[i];
        selected[i] = false;
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> cards(n);
    for(int i=0; i<n; i++) cin >> cards[i];

    int candidate=0;
    vector<bool> selected(n, false);
    dfs(selected, cards, 0, 0, m, candidate, 0);

    cout << candidate;

    return 0;
}