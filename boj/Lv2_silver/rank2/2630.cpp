#include <iostream>
#include <vector>
using namespace std;

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}

pair<int, int> cutPaper(pair<int, int> row, pair<int, int> col, vector<vector<int>>& paper) {
    bool color = paper[row.first][col.first];
    bool isOneColor = true;
    for(int i=row.first; i<row.second; i++) {
        for(int j=col.first; j<col.second; j++) {
            if(color == paper[i][j]) continue;

            isOneColor = false;
            break;
        } if(!isOneColor) break;
    }

    if(isOneColor && color) return {0, 1};
    else if(isOneColor && !color) return {1, 0};

    pair<int, int> cnt = {0, 0};
    cnt += cutPaper({row.first, (row.first+row.second)/2}, {col.first, (col.first+col.second)/2}, paper);
    cnt += cutPaper({row.first, (row.first+row.second)/2}, {(col.first+col.second)/2, col.second}, paper);
    cnt += cutPaper({(row.first+row.second)/2, row.second}, {col.first, (col.first+col.second)/2}, paper);
    cnt += cutPaper({(row.first+row.second)/2, row.second}, {(col.first+col.second)/2, col.second}, paper);
    return cnt;
}

int main(void) {
    int n; scanf("%d", &n);
    vector<vector<int>> paper(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &paper[i][j]);

    pair<int, int> answer = cutPaper({0, n}, {0, n}, paper);
    printf("%d\n%d", answer.first, answer.second);

    return 0;
}