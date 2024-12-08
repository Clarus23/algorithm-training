#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct comp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return (a.second < b.second);
    }
};

void operator+=(vector<int>& a, const vector<int>& b) {
    for(int i=0; i<a.size(); i++) a[i] += b[i];
}

vector<int> dijkstra(int start, int n, vector<pair<int, int>> graph[]) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q;

    dist[start] = 0;
    q.push({start, 0});
    while(!q.empty()) {
        pair<int, int> cur = q.top(); q.pop();

        for(const pair<int, int>& next : graph[cur.first]) {
            if(dist[next.first] > cur.second + next.second) {
                dist[next.first] = cur.second + next.second;
                q.push({next.first, dist[next.first]});
            }
        }
    }

    return dist;
}

int main() {
    int v, e, x;
    scanf("%d %d %d", &v, &e, &x);

    vector<pair<int, int>> graph[v];
    vector<pair<int, int>> reverseGraph[v];
    for(int i=0; i<e; i++) {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);

        graph[start-1].push_back({end-1, weight});
        reverseGraph[end-1].push_back({start-1, weight});
    }

    vector<int> dist(v, 0);
    dist += dijkstra(x-1, v, graph);              // x에서 돌아오는 거리
    dist += dijkstra(x-1, v, reverseGraph); // x까지 가는 거리

    printf("%d", *max_element(dist.begin(), dist.end()));

    return 0;
}