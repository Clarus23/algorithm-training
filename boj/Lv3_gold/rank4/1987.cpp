#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first+b.first, a.second+b.second};
}

int main() {
    int r, c;
    cin >> r >> c;
    int answer = 0;

    const pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<string> board(r);
    for(int i=0; i<r; i++) cin >> board[i];

    vector<bool> isAppear(26, false);
    vector<tuple<pair<int, int>, int, int>> stack(2*r*c);
    int stackTop = -1;

    stack[++stackTop] = {{0, 0}, 1, 0};
    while(stackTop != -1) {
        pair<int, int> coord = get<0>(stack[stackTop]);
        int score = get<1>(stack[stackTop]);
        int restart = get<2>(stack[stackTop--]);

        bool flag = false;
        isAppear[board[coord.first][coord.second] - 'A'] = true;
        for(int i=restart; i<4; i++) {
            pair<int, int> next = coord+dirs[i];

            if(next.first<0 || next.first>=r || next.second<0 || next.second>=c) continue;
            if(isAppear[board[next.first][next.second] - 'A']) continue;

            stack[++stackTop] = {coord, score, i+1};
            stack[++stackTop] = {next, score+1, 0};
            flag = true;
            break;
        }
        if(flag) continue;

        isAppear[board[coord.first][coord.second] - 'A'] = false;
        answer = (score > answer) ? score : answer;
    }

    cout << answer;

    return 0;
}