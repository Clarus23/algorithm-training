#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(vector<string>& maps, int x, int y) {
    queue<pair<int, int>> bfs;
    int udlr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우 좌표
    
    int resource = (maps[x][y] - '0');
    maps[x][y] = 'X';
    bfs.push({x, y});
    while(!bfs.empty()) {
        int row = bfs.front().first;
        int col = bfs.front().second;
        bfs.pop();

        for(int i=0; i<4; i++) {
            if(row+udlr[i][0] >= 0 && row+udlr[i][0] < maps.size() &&
               col+udlr[i][1] >= 0 && col+udlr[i][1] < maps[0].size()) {
                if(maps[row+udlr[i][0]][col+udlr[i][1]] != 'X') {
                    resource += (maps[row+udlr[i][0]][col+udlr[i][1]] - '0');
                    maps[row+udlr[i][0]][col+udlr[i][1]] = 'X';
                    bfs.push({row+udlr[i][0], col+udlr[i][1]});
                }
            }
        }
    }

    return resource;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for(int i=0; i<maps.size(); i++)
        for(int j=0; j<maps[0].size(); j++)
            if(maps[i][j] != 'X') answer.push_back(bfs(maps, i, j));
    
    if(answer.empty()) return {-1};
    
    sort(answer.begin(), answer.end());
    
    return answer;
}