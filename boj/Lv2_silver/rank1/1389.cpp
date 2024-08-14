#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<set<int>> relation(n);
    while(m--) {
        int s, e;
        scanf("%d %d", &s, &e);

        relation[s-1].insert(e-1);
        relation[e-1].insert(s-1);
    }

    vector<int> kevinNum(n, 0);
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++) {
        vector<bool> isVisited(n, false);

        q.push({i, 0});
        isVisited[i] = true;
        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            kevinNum[i] += cur.second;

            for(int it : relation[cur.first]) {
                if(isVisited[it]) continue;

                q.push({it, cur.second+1});
                isVisited[it] = true;
            }
        }
    }
    printf("%d", (int)(min_element(kevinNum.begin(), kevinNum.end()) - kevinNum.begin() + 1));

    return 0;
}