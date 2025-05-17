#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class BlockGroup {
public:
    pair<int, int> standard;
    set<pair<int, int>> blocks;
    int size;
    int rainbowBlocks;

    BlockGroup() {}
    BlockGroup(pair<int, int>& standard, set<pair<int, int>>& blocks, int size, int rainbowBlocks) {
        this->standard = standard;
        this->blocks = blocks;
        this->size = size;
        this->rainbowBlocks = rainbowBlocks;
    }
};

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}

void gravityFunc(vector<vector<pair<int, bool>>>& board, int gravity) {
    // 배열의 회전방향 -> 반시계 90도
    // 그렇다면 중력의 방향
    // 0 : R(b -> e)
    // 1 : C(e -> b)
    // 2 : R(e -> b)
    // 3 : C(b -> e)
    pair<int, int> gravityDirs[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    int n = board.size();

    int startNum = (gravity == 0 || gravity == 3) ? -1 : n;

    for(int i=0; i<n; i++) {
        vector<int> stack(n, -1);
        int top = -1;

        pair<int, int> cur;
        if (gravity % 2 == 0) cur = {startNum, i};
        else cur = {i, startNum};

        while (true) {
            cur += gravityDirs[gravity];

            if (cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= n) {
                pair<int, int> temp = cur;
                while (top > -1) {
                    temp += gravityDirs[(gravity + 2) % 4];
                    board[temp.first][temp.second].first = stack[top--];
                }

                break;
            }
            board[cur.first][cur.second].second = false;

            if (board[cur.first][cur.second].first == -2) continue;
            else if (board[cur.first][cur.second].first == -1) {
                pair<int, int> temp = cur;
                while (top > -1) {
                    temp += gravityDirs[(gravity + 2) % 4];
                    board[temp.first][temp.second].first = stack[top--];
                }
            } else {
                stack[++top] = board[cur.first][cur.second].first;
                board[cur.first][cur.second].first = -2;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int n, m;
    cin >> n >> m;

    // 0 : 무지개 블록, -1 : 검정 블록, -2 : 빈칸
    vector<vector<pair<int, bool>>> board(n, vector<pair<int, bool>>(n, {-2, false}));
    for(auto& i : board) for(auto& j : i) cin >> j.first;

    int gravity = 0;
    int score = 0;
    while(true) {
        vector<BlockGroup> blockGroups;

        for(int row=0; row<n; row++) for(int col=0; col<n; col++) {
            if(board[row][col].second
            || board[row][col].first == -2
            || board[row][col].first == -1
            || board[row][col].first == 0) continue;

            board[row][col].second = true;
            pair<int, int> standard = {row, col};
            int color = board[row][col].first;

            set<pair<int, int>> blocks;
            set<pair<int, int>> rainbowBlocks;

            queue<pair<int, int>> q;
            q.push(standard);
            blocks.insert(standard);
            while(!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();

                for(pair<int, int> next : dirs) {
                    next += cur;
                    if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n) continue;
                    if(board[next.first][next.second].second) continue;
                    if(board[next.first][next.second].first != 0 && board[next.first][next.second].first != color) continue;

                    board[next.first][next.second].second = true;
                    blocks.insert(next);
                    q.push(next);
                    if(board[next.first][next.second].first == 0) rainbowBlocks.insert(next);
                    else {
                        // 중력의 방향에 따라서 기준 블록의 조건이 달라짐.
                        if(gravity == 0) standard = (next.first < standard.first || (next.first == standard.first && next.second < standard.second)) ? next : standard;
                        else if(gravity == 1) standard = (next.second > standard.second || (next.second == standard.second && next.first < standard.first)) ? next : standard;
                        else if(gravity == 2) standard = (next.first > standard.first || (next.first == standard.first && next.second > standard.second)) ? next : standard;
                        else standard = (next.second < standard.second || (next.second == standard.second && next.first > standard.first)) ? next : standard;
                    }
                }
            }

            if(blocks.size() == 1) continue;
            blockGroups.push_back(BlockGroup(standard, blocks, (int)blocks.size(), (int)rainbowBlocks.size()));
            for(auto& it : rainbowBlocks) board[it.first][it.second].second = false;
        }

        if(blockGroups.empty()) break;

        BlockGroup deleteGroup = blockGroups[0];
        for(int i=1; i<blockGroups.size(); i++) {
            if(blockGroups[i].size > deleteGroup.size
            || (blockGroups[i].size == deleteGroup.size && blockGroups[i].rainbowBlocks > deleteGroup.rainbowBlocks)) deleteGroup = blockGroups[i];
            else if(blockGroups[i].size == deleteGroup.size && blockGroups[i].rainbowBlocks == deleteGroup.rainbowBlocks) {
                // 중력의 방향에 따라서 선택할 블록그룹의 우선순위가 달라짐.
                if(gravity == 0) {
                    if(blockGroups[i].standard.first > deleteGroup.standard.first
                    || (blockGroups[i].standard.first == deleteGroup.standard.first && blockGroups[i].standard.second > deleteGroup.standard.second)) deleteGroup = blockGroups[i];
                } else if(gravity == 1) {
                    if(blockGroups[i].standard.second < deleteGroup.standard.second
                    || (blockGroups[i].standard.second == deleteGroup.standard.second && blockGroups[i].standard.first > deleteGroup.standard.first)) deleteGroup = blockGroups[i];
                } else if(gravity == 2) {
                    if(blockGroups[i].standard.first < deleteGroup.standard.first
                    || (blockGroups[i].standard.first == deleteGroup.standard.first && blockGroups[i].standard.second < deleteGroup.standard.second)) deleteGroup = blockGroups[i];
                } else if(gravity == 3) {
                    if(blockGroups[i].standard.second > deleteGroup.standard.second
                    || (blockGroups[i].standard.second == deleteGroup.standard.second && blockGroups[i].standard.first < deleteGroup.standard.first)) deleteGroup = blockGroups[i];
                }
            }
        }

        score += (deleteGroup.size * deleteGroup.size);
        for(const pair<int, int>& it : deleteGroup.blocks) board[it.first][it.second].first = -2;

        gravityFunc(board, gravity);
        gravity = (gravity+1)%4;
        gravityFunc(board, gravity);
    }

    cout << score;

    return 0;
}