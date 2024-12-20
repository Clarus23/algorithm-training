#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

bool operator==(const pair<int, int>& a, int b) {
    return (a.first == b || a.second == b);
}

int dijkstra1(int start, int goal, int v, vector<pair<int, int>>* graph) {
    vector<int> distance(v, INT_MAX);
    distance[start] = 0;

    priority_queue<pair<int, int>> q;
    q.push({-distance[start], start});
    while(!q.empty()) {
        int curNode = q.top().second;
        int curDistance = -q.top().first;
        q.pop();

        for(pair<int, int>& next : graph[curNode]) {
            if(distance[next.first] > curDistance + next.second) {
                distance[next.first] = curDistance + next.second;
                q.push({-distance[next.first], next.first});
            }
        }
    }

    return distance[goal];
}

pair<int, int> dijkstra2(int start, int goal1, int goal2, int v, vector<pair<int, int>>* graph) {
    vector<int> distance(v, INT_MAX);
    distance[start] = 0;

    priority_queue<pair<int, int>> q;
    q.push({-distance[start], start});
    while(!q.empty()) {
        int curNode = q.top().second;
        int curDistance = -q.top().first;
        q.pop();

        for(pair<int, int>& next : graph[curNode]) {
            if(distance[next.first] > curDistance + next.second) {
                distance[next.first] = curDistance + next.second;
                q.push({-distance[next.first], next.first});
            }
        }
    }

    return {distance[goal1], distance[goal2]};
}

int main() {
    int v, e; scanf("%d %d", &v, &e);
    vector<pair<int, int>> graph[v];
    for(int i=0; i<e; i++) {
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);

        graph[v1-1].push_back({v2-1, w});
        graph[v2-1].push_back({v1-1, w});
    }
    int v1, v2; scanf("%d %d", &v1, &v2);

    int mPath = dijkstra1(v1-1, v2-1, v, graph);
    pair<int, int> s2mPath = dijkstra2(0, v1-1, v2-1, v, graph);
    pair<int, int> e2mPath = dijkstra2(v-1, v1-1, v2-1, v, graph);

    if(mPath == INT_MAX || s2mPath == INT_MAX || e2mPath == INT_MAX) {
        printf("-1");
    } else printf("%d", min(s2mPath.first+e2mPath.second, s2mPath.second+e2mPath.first) + mPath);

    return 0;
}