#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n; scanf("%d", &n);

    vector<vector<int>> graph(n, vector<int>(n, false));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &graph[i][j]);

    for(int i=0; i<n; i++) {
        vector<bool> isVisited(n, false);
        queue<int> q;
        q.push(i);
        isVisited[i] = true;
        while(!q.empty()) {
            int cur = q.front(); q.pop();

            for(int j=0; j<n; j++) {
                if(graph[cur][j]) {
                    graph[i][j] = 1;
                    if(!isVisited[j]) {
                        q.push(j);
                        isVisited[j] = true;
                    }
                }
            }
        }
    }

    for(vector<int> row : graph) {
        for(int node : row) printf("%d ", node);
        printf("\n");
    }

    return 0;
}