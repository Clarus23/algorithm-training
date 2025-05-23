#include <iostream>
#include <vector>
using namespace std;

class Shark {
public:
    pair<int, int> coord;
    int dir;
    bool isLive;
};

class BoardInfo {
public:
    int shark;
    int smell;
    int remain;

    void setBoard(int a, int b, int c) {
        shark = a;
        smell = b;
        remain = c;
    }
};

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first+b.first, a.second+b.second};
}
bool isInArea(pair<int, int> coord, int n) {
    return (coord.first >= 0 && coord.first < n && coord.second >= 0 && coord.second < n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    const pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<Shark> sharkInfo(m);
    vector<vector<BoardInfo>> board(n, vector<BoardInfo>(n));
    vector<vector<vector<int>>> priority(m, vector<vector<int>>(4, vector<int>(4)));

    for(int row=0; row<n; row++) for(int col=0; col<n; col++) {
        cin >> board[row][col].shark;
        --board[row][col].shark;
        board[row][col].smell = board[row][col].shark;
        board[row][col].remain = k;

        sharkInfo[board[row][col].shark].coord = {row, col};
    }
    for(int i=0; i<m; i++) {
        cin >> sharkInfo[i].dir;
        --sharkInfo[i].dir;

        sharkInfo[i].isLive = true;
    }

    for(int shark=0; shark<m; shark++) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                cin >> priority[shark][i][j];
                --priority[shark][i][j];
            }
        }
    }

    // 상어의 이동 우선순위 : dirs[상어번호][현재방향]

    int remainShark = m;
    int second = 0;
    while(second <= 1000) {
        if(remainShark == 1) {
            cout << second;
            return 0;
        }

        vector<vector<BoardInfo>> nextBoard(n, vector<BoardInfo>(n));
        for(int row=0; row<n; row++) for(int col=0; col<n; col++) {
            nextBoard[row][col].shark = -1;
            nextBoard[row][col].smell = board[row][col].smell;
            nextBoard[row][col].remain = board[row][col].remain-1;

            if(nextBoard[row][col].remain == 0) nextBoard[row][col].smell = -1;
        }

        for(int sharkNum=0; sharkNum<m; sharkNum++) {
            if(!sharkInfo[sharkNum].isLive) continue;

            Shark& curShark = sharkInfo[sharkNum];
            pair<pair<int, int>, int> spare = {{n, n}, -1};
            bool isMove = false;
            for(const int& dir : priority[sharkNum][curShark.dir]) {
                pair<int, int> next = curShark.coord + dirs[dir];

                if(!isInArea(next, n)) continue;

                if(board[next.first][next.second].smell == -1) {
                    isMove = true;

                    if(nextBoard[next.first][next.second].shark != -1) {
                        curShark.isLive = false;
                        --remainShark;
                        break;
                    }

                    nextBoard[next.first][next.second].setBoard(sharkNum, sharkNum, k);

                    curShark.coord = next;
                    curShark.dir = dir;
                    break;
                } else if(board[next.first][next.second].smell == sharkNum) {
                    if(spare.second != -1) continue;

                    spare = {next, dir};
                }
            }

            if(!isMove) {
                nextBoard[spare.first.first][spare.first.second].setBoard(sharkNum, sharkNum, k);

                curShark.coord = spare.first;
                curShark.dir = spare.second;
            }
        }


        board.swap(nextBoard);
        ++second;
    }

    cout << -1;

    return 0;
}
