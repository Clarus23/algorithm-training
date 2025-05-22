#include <iostream>
#include <vector>
using namespace std;

class Fish {
public:
    pair<int, int> coord;
    int dir;
    bool isLive;

    Fish() {}
    Fish(pair<int, int> coord, int dir) {
        this->coord = coord;
        this->dir = dir;
        isLive = true;
    }
};

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first + b.first, a.second + b.second};
}
void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}

bool operator==(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first == b.first && a.second == b.second);
}

void moveFish(vector<Fish>& fishes, vector<vector<int>>& board, pair<int, int> sharkPos, const pair<int, int> dirs[]) {
    for(int idx=0; idx<16; idx++) {
        if(!fishes[idx].isLive) continue;

        Fish& fish = fishes[idx];
        for(int i=0; i<8; i++) {
            int dir = (fish.dir + i)%8;

            pair<int, int> nextPos = fish.coord + dirs[dir];
            if(nextPos.first < 0 || nextPos.first >= 4 || nextPos.second < 0 || nextPos.second >= 4) continue;
            if(nextPos == sharkPos) continue;

            int targetIdx = board[nextPos.first][nextPos.second];

            board[fish.coord.first][fish.coord.second] = targetIdx;
            if(targetIdx != -1)
                fishes[targetIdx].coord = fish.coord;
            fish.coord = nextPos;
            fish.dir = dir;
            board[fish.coord.first][fish.coord.second] = idx;

            break;
        }
    }
}

int dfs(vector<Fish>& fishes, vector<vector<int>>& board, Fish shark, int point, const pair<int, int> dirs[]) {
    int result = point;

    moveFish(fishes, board, shark.coord, dirs);

    for(int i=0; i<3; i++) {
        shark.coord += dirs[shark.dir];

        if(shark.coord.first < 0 || shark.coord.first >= 4 || shark.coord.second < 0 || shark.coord.second >= 4) break;
        if(board[shark.coord.first][shark.coord.second] == -1) continue;

        int targetNum = board[shark.coord.first][shark.coord.second];
        vector<Fish> newFishes = fishes;
        vector<vector<int>> newBoard = board;

        newBoard[shark.coord.first][shark.coord.second] = -1;
        newFishes[targetNum].isLive = false;
        Fish newShark(shark.coord, newFishes[targetNum].dir);

        result = max(result, dfs(newFishes, newBoard, newShark, point + targetNum+1, dirs));
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> dirs[8] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

    vector<Fish> fishes(16);
    vector<vector<int>> board(4, vector<int>(4));

    for(int row=0; row<4; row++) for(int col=0; col<4; col++) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        fishes[a] = Fish({row, col}, b);
        board[row][col] = a;
    }

    int eatFish = board[0][0];
    board[0][0] = -1;
    fishes[eatFish].isLive = false;
    Fish shark({0, 0}, fishes[eatFish].dir);

    int point = dfs(fishes, board, shark, eatFish+1, dirs);
    cout << point;

    return 0;
}