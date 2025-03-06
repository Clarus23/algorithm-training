#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    scanf("%d\n%d", &n, &m);

    vector<vector<int>> roadMap(n, vector<int>(n, INT_MAX));
    for(int i=0; i<m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        roadMap[a-1][b-1] = (roadMap[a-1][b-1] > c) ? c : roadMap[a-1][b-1];
    }

    for(int mid=0; mid<n; mid++) {
        for (int start = 0; start < n; start++) {
            for (int end = 0; end < n; end++) {
                if (start == end) continue;

                roadMap[start][end] =
                        ((long long) roadMap[start][mid] + roadMap[mid][end] < roadMap[start][end])
                        ? roadMap[start][mid] + roadMap[mid][end] : roadMap[start][end];
            }
        }
    }


    for(const vector<int>& row : roadMap) {
        for(int cost : row) printf("%d ", (cost != INT_MAX) ? cost : 0);
        printf("\n");
    }

    return 0;
}