#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* # 풀이 아이디어: Kruskal 
* ## Kruskal 을 이용해 최소 비용의 스패닝 트리를 만든다.
*
* # 시간복잡도: O(MlogM)
*
* # 메모리: 3,196 kb
* # 실행시간: 28 ms
* # 난이도: 하
*/

class Connect {
public:
	int s, e;
	int w;
	
	Connect() {}
	Connect(int s, int e, int w) {
		this->s = s;
		this->e = e;
		this->w = w;
	}
	
	bool operator<(Connect o) {
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
	
	int n, m;
	cin >> n >> m;
	
	vector<int> parent(n, -1);
	vector<Connect> network(m);
	for(Connect& lan : network) {
		cin >> lan.s >> lan.e >> lan.w;
		--lan.s; --lan.e;
	} sort(network.begin(), network.end());
	
	int cnt=0; int cost = 0;
	for(Connect& lan : network) {
		if(!merge(parent, lan.s, lan.e)) continue;
		
		++cnt;
		cost += lan.w;
		if(cnt == n-1) break;
	}
	
	cout << cost;
	
	return 0;
}