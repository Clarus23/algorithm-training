#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
    int prevPoint[4] = {0,};
    int curPoint[4] = {0, };
    
    for(int i=0; i<4; i++) prevPoint[i] = land[0][i];
    for(int i=1; i<land.size(); i++) {
        for(int j=0; j<4; j++) 
            curPoint[j] = land[i][j] + max({prevPoint[(j+1)%4],prevPoint[(j+2)%4],prevPoint[(j+3)%4]});
        
        for(int j=0; j<4; j++) prevPoint[j] = curPoint[j];
    }
    
    return *max_element(prevPoint, prevPoint+4);
}