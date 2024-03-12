#include <vector>
#include <algorithm>
#include <set>

using namespace std;

pair<int, int>& operator+=(pair<int, int>& left, const pair<int, int>& right) {
    left.first += right.first;
    left.second += right.second;
    return left;
}

int solution(vector<vector<int>> land) {
    const int maxRow = land.size();
    const int maxCol = land[0].size();
    const pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    vector<int> oils(maxCol, 0);
    set<int> targetCols;
    
    vector<pair<int, int>> stack;
    for(int row=0; row<maxRow; row++) for(int col=0; col<maxCol; col++) {
        if(!land[row][col]) continue;
        
        stack.push_back(make_pair(row, col));
        land[row][col]=0; int cnt=1;
        while(!stack.empty()) {
            const pair<int, int> cur = stack.back(); stack.pop_back();
            targetCols.insert(cur.second);
            
            for(pair<int, int> next : dirs) {
                next += cur;
                
                if(next.first<0 || next.first>=maxRow || next.second<0 || next.second>=maxCol) continue;
                if(!land[next.first][next.second]) continue;
                
                stack.push_back(next);
                land[next.first][next.second]=0; cnt++;
            }
        }
        
        for(auto t : targetCols) oils[t] += cnt;
        targetCols.clear();
    }
    
    return *max_element(oils.begin(), oils.end());
}