#include <iostream>
#include <vector>
using namespace std;

/*
* # 풀이 아이디어: union - find
* ## union 함수를 이용해 합치고,
* ## find 함수를 이용해 찾는다.
*
* # 시간복잡도: O(NM)
*
* # 메모리: 5,928 kb
* # 실행시간: 28 ms
* # 체감난이도: 하
*/

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int find(vector<int>& parent, int x) {
    if (parent[x] < 0) return x;

    return (parent[x] = find(parent, parent[x]));
}

void merge(vector<int>& parent, int x, int y) {
    x = find(parent, x);
    y = find(parent, y);

    if (x == y) return;

    if (parent[x] == parent[y]) --parent[x];
    else if (parent[x] > parent[y]) swap(x, y);

    parent[y] = x;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n+1, -1);

    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 0) merge(parent, x, y);
        else cout << ((find(parent, x) == find(parent, y)) ? "YES" : "NO") << "\n";
    }

    return 0;
}