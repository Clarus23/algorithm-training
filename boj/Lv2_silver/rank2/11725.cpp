#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    int n; scanf("%d", &n);
    vector<int> parent(n, -1);
    vector<vector<int>> graph(n, vector<int>(0));
    for(int i=1; i<n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(int next : graph[cur]) {
            if(parent[next] != -1) continue;

            parent[next] = cur+1;
            q.push(next);
        }
    }

    for(int i=1; i<n; i++) printf("%d\n", parent[i]);

    return 0;
}