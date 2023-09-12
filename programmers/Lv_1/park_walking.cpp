#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int moveRow[4] = {0, 0, 1, -1};
    int moveCol[4] = {1, -1, 0, 0};
    map<char, int> ewsn = {
        {'E', 0}, {'W', 1}, {'S', 2}, {'N', 3}
    };
    
    int H = park.size(), W = park[0].size();
    int row = -1, col = -1;
    
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(park[i][j] == 'S') {
                row = i; col = j;
                break;
            }
        }
        if(row != -1) break;
    }
    
    for(string route : routes) {
        char op = route[0];
        int n = route[2]-'0';
        
        bool move = true;
        int prev_row = row;
        int prev_col = col;
        
        for(int i=0; i<n; i++) {
            row += moveRow[ewsn.find(op)->second];
            col += moveCol[ewsn.find(op)->second];
            
            if(row >= H || row < 0 || col >= W || col < 0 ) {
                move = false; break;
            } else if(park[row][col] == 'X') {
                move = false; break;
            }
        }
        
        if(!move) {
            row = prev_row;
            col = prev_col;
        }
    }
    
    answer.push_back(row);
    answer.push_back(col);
    return answer;
}