#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* # 풀이 아이디어: Kruskal algorithm
* ## Kruskal algorithm 을 통해 최소 스패닝 트리를 만든다.
*
* # 시간 복잡도: O(E*logE)
*
* # 메모리: 3,748 kb
* # 실행시간: 32 ms
* # 체감난이도: 하
*/

typedef long long ll;

class Edge {
public:
	int s, e;
	ll w;
	
	Edge() {}
	Edge(int s, int e, ll w) {
		this->s = s;
		this->e = e;
		this->w = w;
	}
	
	bool operator< (const Edge& o) const {
		return (w < o.w);
	}
};

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int find(vector<int>& parent, int x) {
	if(parent[x] < 0) return x;
	return (parent[x] = find(parent, parent[x]));
}

bool merge(vector<int>& parent, int x, int y) {
	x = find(parent, x); y = find(parent, y);
	if(x == y) return false;
	
	if(parent[x] == parent[y]) --parent[x];
	else if(parent[x] > parent[y]) swap(x, y);
	
	parent[y] = x;
	return true;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int v, e;
	cin >> v >> e;
	
	vector<int> parent(v, -1);
	vector<Edge> edges(e);
	for(Edge& edge : edges) {
		cin >> edge.s >> edge.e >> edge.w;
		--edge.s; --edge.e;
	}
	sort(edges.begin(), edges.end());
	
	int cnt=0; ll length = 0;
	for(Edge& edge : edges) {
		if(!merge(parent, edge.s, edge.e)) continue;
		
		++cnt;
		length += edge.w;
		if(cnt == v-1) break;
	}
	
	cout << length;
	
	return 0;
}