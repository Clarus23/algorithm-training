#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
	int to;
	int distance;
	
	Edge() {}
	Edge(int to1, int distance1)
		: to(to1), distance(distance1) {}
};

int n;
vector<vector<Edge>> graph;
vector<vector<int>> dists;

void init(int N, int K, int sBuilding[], int eBuilding[], int mDistance[]) {
	
	n = N;
	vector<vector<Edge>>(n).swap(graph);
	dists.assign(2, vector<int>(n, 0));
	
	for(int i=0; i<K; ++i) {
		graph[sBuilding[i]].emplace_back(eBuilding[i], mDistance[i]);
		graph[eBuilding[i]].emplace_back(sBuilding[i], mDistance[i]);
	}
	
	return;
}

void add(int sBuilding, int eBuilding, int mDistance) {
	
	graph[sBuilding].emplace_back(eBuilding, mDistance);
	graph[eBuilding].emplace_back(sBuilding, mDistance);
	
	return;
}

int calculate(int M, int mCoffee[], int P, int mBakery[], int R) {
	fill(dists[0].begin(), dists[0].end(), 2e9);
	fill(dists[1].begin(), dists[1].end(), 2e9);
	
	priority_queue<pair<int, pair<int, bool>>> pq;
	for(int i=0; i<M; ++i) {
		dists[0][mCoffee[i]] = 0;
		pq.push({0, {mCoffee[i], 0}});
	}
	for(int i=0; i<P; ++i) {
		dists[1][mBakery[i]] = 0;
		pq.push({0, {mBakery[i], 1}});
	}
	
	int min = 2e9;
	while(!pq.empty()) {
		int curDist = -1 * pq.top().first;
		int curNode = pq.top().second.first;
		bool shopFlag = pq.top().second.second;
		pq.pop();
		
		if(curDist >= R || curDist > dists[shopFlag][curNode] || curDist >= min) continue;
		
		for(const Edge& e : graph[curNode]) {
			int dist = curDist + e.distance;
			
			if(dist > R || dist >= dists[shopFlag][e.to]) continue;
			
			dists[shopFlag][e.to] = dist;
			
			int sumDist = dists[0][e.to] + dists[1][e.to];
			if(dists[!shopFlag][e.to] != 0)
				min = (sumDist < min ? sumDist : min);
			
			if(dist != R) pq.push({-1 * dist, {e.to, shopFlag}});
		}
	}
	
	return (min == 2e9 ? -1 : min);
}
