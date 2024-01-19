#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<string> maps) {
    pair<int, int> dirs[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    const int maxRow = maps.size();
    const int maxCol = maps[0].size();
    
    bool findStart = false;
    int sRow, sCol;
    for(sRow=0; sRow<maxRow; sRow++) {
        for(sCol=0; sCol<maxCol; sCol++) if(maps[sRow][sCol] == 'S') {
            findStart = true; break;
        } if(findStart) break;
    }
    
    bool findLever = false;
    queue<tuple<int, int, int>> bfs;
    bfs.push({sRow, sCol, 0});
    while(!bfs.empty()) {
        int row=get<0>(bfs.front());
        int col=get<1>(bfs.front());
        int cnt=get<2>(bfs.front());
        bfs.pop();
        
        for(pair<int, int> dir : dirs) {
            int curRow = row+dir.first;
            int curCol = col+dir.second;
            if(curRow<0 || curRow>=maxRow || curCol<0 || curCol>=maxCol) continue;
            
            // 지나간 부분은 소문자로 표기, 소문자는 레버를 당긴 후에만 지나갈수 있음.
            if(maps[curRow][curCol] == 'O') {
                maps[curRow][curCol] = (findLever) ? 'x' : 'o';
                bfs.push({curRow, curCol, cnt+1}); continue;
            }
            if((maps[curRow][curCol] == 'o' || maps[curRow][curCol] == 'S') && findLever) {
                maps[curRow][curCol] = 'x';
                bfs.push({curRow, curCol, cnt+1}); continue;
            }
            if(maps[curRow][curCol] == 'E') {
                if(findLever) return cnt+1;
                
                maps[curRow][curCol] == 'e';
                bfs.push({curRow, curCol, cnt+1}); continue;
            }
            if(maps[curRow][curCol] == 'e' && findLever) return cnt+1;
            if(maps[curRow][curCol] == 'L') {
                findLever = true;
                maps[curRow][curCol] = 'l';
                bfs = queue<tuple<int, int, int>>();
                bfs.push({curRow, curCol, cnt+1}); break;
            }
        }
    }
    
    return -1;
}