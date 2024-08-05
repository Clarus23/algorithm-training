#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<bool> isInvited(n, false);
    vector<vector<bool>> graph(n, vector<bool>(n, false));

    while(m--) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u-1][v-1] = true;
        graph[v-1][u-1] = true;
    }
    int cnt=0;
    for(int i=0; i<n; i++) {
        if(isInvited[i]) continue;

        cnt++;
        vector<int> subGraph(1, i);
        while(!subGraph.empty()) {
            int cur = subGraph.back(); subGraph.pop_back();

            for(int j=0; j<n; j++) if(!isInvited[j] && graph[cur][j]) {
                subGraph.push_back(j);
                isInvited[j] = true;
            }
        }
    } printf("%d", cnt);

    return 0;
}