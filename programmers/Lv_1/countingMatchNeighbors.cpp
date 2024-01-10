#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    for(pair<int, int> dir : dirs)
        if(h+dir.first>=0 && h+dir.first<board.size() && w+dir.second>=0 && w+dir.second<board.size())
            if(board[h][w] == board[h+dir.first][w+dir.second]) answer++;
    
    return answer;
}