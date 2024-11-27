#include <iostream>
#include <vector>
using namespace std;

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first+b.first, a.second+b.second};
}

bool operator==(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first == b.first && a.second == b.second);
}

void oneLineShape(const vector<vector<int>>& board, const pair<int, int>* dirs
        , const pair<int, int>& prev, const pair<int, int>& cur, int score
        , int depth, int& answer) {
    if(depth == 3) {
        answer = (score > answer) ? score : answer;
        return;
    }

    for(int i=0; i<4; i++) {
        pair<int, int> next = cur + dirs[i];
        if(next.first < 0 || next.first >= board.size() || next.second < 0 || next.second >= board[0].size()) continue;
        if(next == prev) continue;

        oneLineShape(board, dirs, cur, next, score+board[next.first][next.second], depth+1, answer);
    }
}

void tShape(const vector<vector<int>>& board, const pair<int, int>* dirs
            , const pair<int, int>& cur, int& answer) {
    for(int i=0; i<4; i++) {
        pair<int, int> block1 = cur + dirs[i];
        if(block1.first < 0 || block1.first >= board.size() || block1.second < 0 || block1.second >= board[0].size()) continue;

        pair<int, int> block2 = block1 + dirs[i];
        if(block2.first < 0 || block2.first >= board.size() || block2.second < 0 || block2.second >= board[0].size()) continue;

        int score =  board[cur.first][cur.second]
                     + board[block1.first][block1.second]
                     + board[block2.first][block2.second];

        pair<int, int> block3_1 = block1 + dirs[(i+1)%4];
        pair<int, int> block3_2 = block1 + dirs[(i+3)%4];
        if(block3_1.first >= 0 && block3_1.first < board.size() && block3_1.second >= 0 && block3_1.second < board[0].size()) {
            int score1 = score + board[block3_1.first][block3_1.second];
            answer = (score1 > answer) ? score1 : answer;
        }
        if(block3_2.first >= 0 && block3_2.first < board.size() && block3_2.second >= 0 && block3_2.second < board[0].size()) {
            int score2 = score + board[block3_2.first][block3_2.second];
            answer = (score2 > answer) ? score2 : answer;
        }
    }
}

int main() {
    const pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> board(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &board[i][j]);

    int answer = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            vector<pair<pair<int, int>, int>> coordNScore(4);
            int top = -1;

            oneLineShape(board, dirs, {-1, -1}, {i, j}, board[i][j], 0, answer);
            tShape(board, dirs, {i, j}, answer);
        }
    }

    printf("%d", answer);

    return 0;
}