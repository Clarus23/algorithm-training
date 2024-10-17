#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m;
    scanf("%d\n%d", &n, &m);
    vector<vector<int>> costs(n, vector<int>(n, -1));
    while(m--) {
        int s, e, c;
        scanf("%d %d %d", &s, &e, &c);
        costs[s-1][e-1] = (costs[s-1][e-1] == -1 || c < costs[s-1][e-1]) ? c : costs[s-1][e-1];
    }

    int startNode, endNode;
    scanf("%d %d", &startNode, &endNode);

    vector<pair<int, bool>> costNVisited(n, {INT_MAX, false});
    costNVisited[startNode-1] = {0, false};
    while(true) {
        int curNode = min_element(costNVisited.begin(), costNVisited.end(), [](const pair<int, bool>& a, const pair<int, bool>& b){
            return (a.second < b.second) || (a.second == b.second && a.first < b.first);
        }) - costNVisited.begin();
        costNVisited[curNode].second = true;

        if(curNode == endNode-1) break;

        for(int i=0; i<n; i++) {
            if(costs[curNode][i] == -1) continue;
            costNVisited[i].first = min(costNVisited[curNode].first + costs[curNode][i], costNVisited[i].first);
        }
    }

    printf("%d", costNVisited[endNode-1].first);

    return 0;
}