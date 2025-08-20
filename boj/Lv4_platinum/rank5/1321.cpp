#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * # 풀이 아이디어: segment tree
 * ## segment tree의 높이(H)를 구한다. (log2(N))
 * ## segment tree를 배열로 구현한다 (capacity: 1 << (H+1))
 * ## segtree 만들기, 업데이트, 서칭을 각각 재귀로 구현한다.
 *
 * # 메모리: 12,188 kb
 * # 실행시간: 44 ms
 */

long long makeSegTree(vector<long long>& segtree, const vector<int>& arr, int node, int start, int end) {
	if(start == end) return (segtree[node] = arr[start]);
	
	int mid = (start + end)/2;
	
	return (segtree[node] = makeSegTree(segtree, arr, node*2, start, mid)
							+ makeSegTree(segtree, arr, node*2+1, mid+1, end));
}

void updateSegTree(vector<long long>& segtree, int node, int target, int start, int end, int val) {
	if(target < start || target > end) return;
	
	segtree[node] += val;
	if(start == end) return;
	
	int mid = (start + end)/2;
	
	updateSegTree(segtree, node*2, target, start, mid, val);
	updateSegTree(segtree, node*2+1, target, mid+1, end, val);
}

int searchSegTree(vector<long long>& segtree, int node, long long target, int start, int end) {
	if(start == end) return start;
	
	long long leftInfantry = segtree[node*2];
	
	int mid = (start + end)/2;
	
	if(target > leftInfantry)
		return searchSegTree(segtree, node*2+1, target - leftInfantry, mid+1, end);
	
	return searchSegTree(segtree, node*2, target, start, mid);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n; cin >> n;
	vector<int> infantry(n);
	for(int& idx : infantry) cin >> idx;
	
	int h = ceil(log2(n)); // segment tree의 높이
	vector<long long> segtree(1<<(h+1));
	
	makeSegTree(segtree, infantry, 1, 0, n-1);
	
	int m; cin >> m;
	for(int i=0; i<m; ++i) {
		int cmd; cin >> cmd;
		
		if(cmd == 1) {
			int infantry, soldiers;
			cin >> infantry >> soldiers;
			updateSegTree(segtree, 1, infantry-1, 0, n-1, soldiers);
		} else {
			long long soldier; cin >> soldier;
			cout << searchSegTree(segtree, 1, soldier, 0, n-1)+1 << "\n";
		}
	}
	
	return 0;
}