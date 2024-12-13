#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(int start, int n, vector<pair<int, int>> graph[]) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>> q;

    dist[start] = 0;
    q.push({-dist[start], start});
    while(!q.empty()) {
        pair<int, int> cur = q.top(); q.pop();

        for(const pair<int, int>& next : graph[cur.second]) {
            if(dist[next.first] > next.second - cur.first) {
                dist[next.first] = next.second - cur.first;
                q.push({-dist[next.first], next.first});
            }
        }
    }

    return dist;
}

int main() {
    int v, e; scanf("%d %d", &v, &e);
    vector<pair<int, int>> graph[v];

    int startNode; scanf("%d", &startNode);
    for(int i=0; i<e; i++) {
        int a, b, w; scanf("%d %d %d", &a, &b, &w);

        graph[a-1].push_back({b-1, w});
    }

    vector<int> dist = dijkstra(startNode-1, v, graph);
    for(const int& num : dist) {
        if(num == INT_MAX) printf("INF\n");
        else printf("%d\n", num);
    }

    return 0;
}