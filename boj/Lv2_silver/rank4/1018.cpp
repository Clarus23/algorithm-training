#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    char color[2] = {'B', 'W'};
    int n, m; cin >> n >> m;

    char c;
    vector<vector<bool>> coloring(n, vector<bool>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> c;
            coloring[i][j] = (c == color[(i+j)%2]);
        }
    }

    int draw, minElement=64;
    for(int i=0; i+7<n; i++) {
        for(int j=0; j+7<m; j++) {
            draw=0;
            for(int row=i; row<i+8; row++)
                for(int col=j; col<j+8; col++)
                    if(coloring[row][col]) draw++;
            minElement = min({minElement, draw, 64-draw});
        }
    }

    cout << minElement;

    return 0;
}