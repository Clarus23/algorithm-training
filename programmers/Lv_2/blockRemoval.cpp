#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<char>> cboard(m, vector<char>(n));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++) cboard[i][j] = board[i][j];
    
    while(true) {
        vector<pair<int, int>> rmCoord;
        
        //삭제할 블록을 찾는 과정
        for(int i=0; i<m-1; i++) {
            for(int j=0; j<n-1; j++) {
                char target = cboard[i][j];
                if(target=='!') continue;

                if(cboard[i+1][j]==target && cboard[i][j+1]==target && cboard[i+1][j+1]==target)
                    rmCoord.push_back({i, j});
            }
        }
        
        //더 이상 삭제할 블록이 없을 때,
        if(rmCoord.empty()) {
            for(vector<char> v : cboard) answer += count(v.begin(), v.end(), '!');
            break;
        }
        
        //블록들을 삭제하는 과정
        for(auto coord : rmCoord) {
            cboard[coord.first][coord.second] = '!';
            cboard[coord.first+1][coord.second] = '!';
            cboard[coord.first][coord.second+1] = '!';
            cboard[coord.first+1][coord.second+1] = '!';
        }
        
        //블록이 빈 공간을 채우며 내려오는 과정
        for(int col=0; col<n; col++) {
            vector<char> temp;
            for(int i=0; i<m; i++) if(cboard[i][col] != '!') temp.push_back(cboard[i][col]);

            int row = m-1;
            while(!temp.empty()) {
                cboard[row--][col] = temp.back(); temp.pop_back();
            }
            while(row>=0)
                cboard[row--][col] = '!';
        }
    }
    
    return answer;
}