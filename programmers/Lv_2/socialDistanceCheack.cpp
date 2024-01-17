#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(vector<string> place : places) {
        bool flag = true;
        for(int row=0; row<5; row++) {
        for(int col=0; col<5; col++) {
            if(place[row][col]!='P') continue;
            
            // distance == 1
            if(row<4) if(place[row+1][col]=='P') { flag = false; break; }
            if(col<4) if(place[row][col+1]=='P') { flag = false; break; }
            // distance == 2
            if(row<3) if(place[row+2][col]=='P' && place[row+1][col]!='X') { flag = false; break; }
            if(col<3) if(place[row][col+2]=='P' && place[row][col+1]!='X') { flag = false; break; }
            if(row>0 && col<4)
                if(place[row-1][col+1]=='P' && !(place[row-1][col]=='X' && place[row][col+1]=='X')) {
                    flag = false; break;
                }
            if(row<4 && col<4)
                if(place[row+1][col+1]=='P' && !(place[row+1][col]=='X' && place[row][col+1]=='X')) {
                    flag = false; break;
                }
        } if(!flag) break;
        }
        
        if(flag) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}