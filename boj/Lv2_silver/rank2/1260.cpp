#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfsF(vector<int>& dfs, vector<bool>& isVisited, vector<vector<bool>>& graph, int n, int v) {
    dfs.push_back(v);
    isVisited[v-1] = true;

    for(int i=0; i<n; i++)
        if(graph[v-1][i] && !isVisited[i])
            dfsF(dfs, isVisited, graph, n, i+1);
}

void bfsF(vector<int>& bfs, vector<vector<bool>>& graph, int n, int v) {
    queue<int> q;
    vector<bool> isVisited(n, false);

    q.push(v-1);
    isVisited[v-1] = true;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        bfs.push_back(cur+1);

        for(int i=0; i<n; i++) if(graph[cur][i] && !isVisited[i]){
            q.push(i);
            isVisited[i] = true;
        }
    }
}

int main(void) {
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[a - 1][b - 1] = true;
        graph[b - 1][a - 1] = true;
    }

    vector<int> dfs;
    vector<bool> isVisited(n, false);
    dfsF(dfs, isVisited, graph, n, v);

    vector<int> bfs;
    bfsF(bfs, graph, n, v);

    for(int i : dfs) printf("%d ", i);
    printf("\n");
    for(int i : bfs) printf("%d ", i);

    return 0;
}