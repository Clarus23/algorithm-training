#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll makeSegTree(vector<ll>& segTree, vector<ll>& arr, int node, int start, int end) {
    if (start == end) return (segTree[node] = arr[start]);

    int mid = (start + end) / 2;
    return (segTree[node] = makeSegTree(segTree, arr, node * 2, start, mid)
                        + makeSegTree(segTree, arr, node * 2 + 1, mid + 1, end));
}

void updateSegTree(vector<ll>& segTree, int node, int start, int end, int target, ll val) {
    if (target < start || target > end) return;

    segTree[node] += val;

    if (start == end) return;
    int mid = (start + end) / 2;

    updateSegTree(segTree, node * 2, start, mid, target, val);
    updateSegTree(segTree, node * 2 + 1, mid + 1, end, target, val);
}

ll get(vector<ll>& segTree, int node, int start, int end, int targetS, int targetE) {
    if (targetS > end || targetE < start) return 0;

    if (targetS <= start && targetE >= end) return segTree[node];

    int mid = (start + end) / 2;
    return get(segTree, node * 2, start, mid, targetS, targetE)
        + get(segTree, node * 2 + 1, mid + 1, end, targetS, targetE);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int h = ceil(log2(n));
    vector<ll> segTree(1 << (h + 1));

    makeSegTree(segTree, arr, 1, 0, n - 1);

    for (int i = 0; i < m+k; ++i) {
        int op; cin >> op;
        ll a, b;
        cin >> a >> b;

        if (op == 1) {
            updateSegTree(segTree, 1, 0, n - 1, a-1, b - arr[a-1]);
            arr[a-1] = b;
        } else {
            cout << get(segTree, 1, 0, n - 1, a-1, b-1) << "\n";
        }
    }

    return 0;
}