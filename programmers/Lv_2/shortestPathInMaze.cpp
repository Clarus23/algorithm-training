#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    queue<tuple<int, int, int>> q;
    
    const int dy[4] = {1, 0, -1, 0};
    const int dx[4] = {0, 1, 0, -1};
    const int maxRow = maps.size()-1;
    const int maxCol = maps[0].size()-1;
    
    maps[0][0] = 0;
    q.push({0,0,1});
    while(!q.empty()) {
        int row = get<0>(q.front());
        int col = get<1>(q.front());
        int move = get<2>(q.front());
        q.pop();
        
        if(row == maxRow && col == maxCol) {
            answer = move;
            break;
        }
        
        for(int i=0; i<4; i++) {
            int drow = row + dy[i];
            int dcol = col + dx[i];
            
            if(drow >= 0 && drow <= maxRow && dcol >= 0 && dcol <= maxCol) {
                if(maps[drow][dcol]) {
                    maps[drow][dcol] = 0;
                    q.push({drow, dcol, move+1});
                }
            }
        }
    }
    
    return answer;
}