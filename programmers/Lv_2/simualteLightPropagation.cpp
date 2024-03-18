#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

pair<int, int>& operator+=(pair<int, int>& left, const pair<int, int>& right) {
    left.first += right.first;
    left.second += right.second;
    return left;
}

class Node {
  public:
    bool ports[4]; //l, r, u, d 순서
    Node() { for(int i=0; i<4; i++) ports[i] = false; }
};

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    const int maxRow = grid.size();
    const int maxCol = grid[0].size();
    int ordersI2C[4] = {'l', 'r', 'u', 'd'};
    map<char, int> ordersC2I = {{'l', 0}, {'r', 1}, {'u', 2}, {'d', 3}};
    map<char, pair<int, int>> dirs = {{'l', {0, -1}}, {'r', {0, 1}}, {'u', {-1, 0}}, {'d', {1, 0}}};
    map<char, map<char, char>> converter = {
        {'S', {{'l', 'l'}, {'r', 'r'}, {'u', 'u'}, {'d', 'd'}}},
        {'L', {{'l', 'd'}, {'r', 'u'}, {'u', 'l'}, {'d', 'r'}}},
        {'R', {{'l', 'u'}, {'r', 'd'}, {'u', 'r'}, {'d', 'l'}}}
    }; // converter[curNode][inDir] => outDir
    
    vector<vector<Node>> visited(maxRow, vector<Node>(maxCol));
    for(int row=0; row<maxRow; row++) for(int col=0; col<maxCol; col++) {
        for(int i=0; i<4; i++) {
            if(visited[row][col].ports[i]) continue;
            visited[row][col].ports[i] = true;
            
            pair<int, int> curP = {row, col};
            char curD = ordersI2C[i];
            int light = 1;
            while(true) {
                curP += dirs[curD];
                if(curP.first < 0) curP.first = maxRow-1;
                else if(curP.first == maxRow) curP.first = 0;
                else if(curP.second < 0) curP.second = maxCol-1;
                else if(curP.second == maxCol) curP.second = 0;
                
                curD = converter[grid[curP.first][curP.second]][curD];
                if(curP.first==row && curP.second==col && curD==ordersI2C[i]) {
                    answer.push_back(light);
                    break;
                }
                visited[curP.first][curP.second].ports[ordersC2I[curD]] = true;
                light++;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}