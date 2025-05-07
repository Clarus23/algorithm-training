#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    pair<int, int> pos;
    int depth;
    char direction;

    Node(pair<int, int> pos, int depth, char direction) {
        this->pos = pos;
        this->depth = depth;
        this->direction = direction;
    }
};

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first + b.first, a.second + b.second};
}

// queue 와 Node 를 사용한 버전 4ms
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pair<int, int> dirs[3] = {{0, -1}, {-1, 0}, {0, 1}};
    char directionCode[3] = {'l', 'u', 'r'};

    int n, m, d;
    cin >> n >> m >> d;

    vector<vector<int>> board(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> board[i][j];

    vector<bool> archerPos(m, false);
    for(int i=0; i<3; i++) archerPos[i] = true;

    int maxKill = 0;
    do {
        int archer[3]; int it = 0;
        for(int i=0; i<m; i++) if(archerPos[i]) archer[it++] = i;
        vector<vector<int>> curBoard(board);

        int killCount = 0;
        for(int row = n-1; row >= 0; row--) {
            pair<int, int> deadEnemy[3];
            int deadCount = 0;
            for(int col : archer) {
                if(curBoard[row][col] == 1) {
                    deadEnemy[deadCount++] = {row, col};
                    curBoard[row][col] = 2;
                    continue;
                } else if(curBoard[row][col] == 2) continue;

                bool endLoop = false;
                queue<Node> q;
                q.push(Node({row, col}, 1, ' '));
                while(!q.empty() && !endLoop) {
                    pair<int, int> curPos = q.front().pos;
                    int depth = q.front().depth;
                    char direction = q.front().direction;
                    q.pop();

                    if(depth+1 > d) continue;

                    for(int i=0; i<3; i++) {
                        if(i==0 && (direction == 'u' || direction == 'r')) continue;
                        if(i==2 && (direction == 'l' || direction == 'u')) continue;

                        pair<int, int> nextPos = curPos + dirs[i];
                        if(nextPos.first < 0 || nextPos.first >= n || nextPos.second < 0 || nextPos.second >= m) continue;

                        if(curBoard[nextPos.first][nextPos.second] == 1) {
                            deadEnemy[deadCount++] = nextPos;
                            curBoard[nextPos.first][nextPos.second] = 2;
                            endLoop = true;
                            break;
                        } else if(curBoard[nextPos.first][nextPos.second] == 2) {
                            endLoop = true;
                            break;
                        }

                        q.push(Node(nextPos, depth+1, directionCode[i]));
                    }
                }
            }

            for(int i=0; i<deadCount; i++)
                curBoard[deadEnemy[i].first][deadEnemy[i].second] = 0;
            killCount += deadCount;
        }

        maxKill = (killCount > maxKill) ? killCount : maxKill;

    } while(prev_permutation(archerPos.begin(), archerPos.end()));

    cout << maxKill;

    return 0;
}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//// queue 와 node 를 사용 안한 버전 0ms
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    int n, m, d;
//    cin >> n >> m >> d;
//
//    vector<vector<int>> board(n, vector<int>(m, 0));
//    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> board[i][j];
//
//    vector<bool> archerPos(m, false);
//    for(int i=0; i<3; i++) archerPos[i] = true;
//
//    int maxKill = 0;
//    do {
//        int archer[3]; int it = 0;
//        for(int i=0; i<m; i++) if(archerPos[i]) archer[it++] = i;
//        vector<vector<int>> curBoard(board);
//
//        int killCount = 0;
//        for(int row = n; row > 0; row--) {
//            pair<int, int> deadEnemy[3];
//            int deadCount = 0;
//
//            for(int col : archer) {
//                bool endLoop = false;
//
//                for(int x=1; x<=d; x++) {
//                    for(int i=0; i<x-1; i++) {
//                        if(row - (i+1) < 0 || col - (x-(i+1)) < 0) continue;
//                        if(curBoard[row - (i+1)][col - (x-(i+1))] == 0) continue;
//
//                        if(curBoard[row - (i+1)][col - (x-(i+1))] == 1) {
//                            curBoard[row - (i+1)][col - (x-(i+1))] = 2;
//                            deadEnemy[deadCount++] = {row - (i+1), col - (x-(i+1))};
//                        }
//                        endLoop = true;
//                        break;
//                    } if(endLoop) break;
//
//                    for(int i=x-1; i>=0; i--) {
//                        if(row - (i+1) < 0 || col + (x-(i+1)) >= m) continue;
//                        if(curBoard[row - (i+1)][col + (x-(i+1))] == 0) continue;
//
//                        if(curBoard[row - (i+1)][col + (x-(i+1))] == 1) {
//                            curBoard[row - (i+1)][col + (x-(i+1))] = 2;
//                            deadEnemy[deadCount++] = {row - (i+1), col + (x-(i+1))};
//                        }
//                        endLoop = true;
//                        break;
//                    } if(endLoop) break;
//                }
//            }
//
//            killCount += deadCount;
//            for(int i=0; i<deadCount; i++)
//                curBoard[deadEnemy[i].first][deadEnemy[i].second] = 0;
//        }
//
//        maxKill = (killCount > maxKill) ? killCount : maxKill;
//
//    } while(prev_permutation(archerPos.begin(), archerPos.end()));
//
//    cout << maxKill;
//
//    return 0;
//}