#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2000000000

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first+b.first, a.second+b.second};
}

bool operator<(const pair<int, int>& a, int n) {
    return (a.first < n || a.second < n);
}
bool operator>=(const pair<int, int>& a, int n) {
    return (a.first >= n || a.second >= n);
}

void dijkstra(vector<string>& board, vector<vector<int>>& dists, const pair<int,int> dirs[]) {
    priority_queue<pair<int, pair<int, int>>> pq;

    pq.push({0, {0, 0}});
    dists[0][0] = 0;
    while(!pq.empty()) {
        int dist = -pq.top().first;
        pair<int, int> cur = pq.top().second;
        pq.pop();

        if(dists[cur.first][cur.second] < dist) continue;

        for(int i=0; i<4; i++) {
            pair<int, int> next = dirs[i] + cur;

            if(next < 0 || next >= (int)board.size()) continue;

            int cost = dist + (board[next.first][next.second] - '0');
            if(cost < dists[next.first][next.second]) {
                dists[next.first][next.second] = cost;
                pq.push({-cost, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int testCase; cin >> testCase;
    for(int t=1; t<=testCase; t++) {
        int n; cin >> n;

        vector<string> board(n);
        vector<vector<int>> dists(n, vector<int>(n, INF));
        for(string& s : board) cin >> s;

        dijkstra(board, dists, dirs);
        cout << '#' << t << ' ' << dists[n-1][n-1] << '\n';
    }

    return 0;
}