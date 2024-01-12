#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> table(rows, vector<int>(columns, 0));
    int cnt=1; for(vector<int>& row : table) for(int& i : row) i = cnt++;
    
    for(vector<int> query : queries) {
        vector<int> temp;
        
        vector<pair<int, int>> dirs(query[3]-query[1], make_pair(0,1)); // 상변
        dirs.insert(dirs.end(), query[2]-query[0], make_pair(1, 0));    // 우변
        dirs.insert(dirs.end(), query[3]-query[1], make_pair(0, -1));   // 하변
        dirs.insert(dirs.end(), query[2]-query[0], make_pair(-1, 0));   // 좌변
        
        pair<int, int> init = make_pair(query[0]-1, query[1]-1);
        int cur = table[init.first][init.second];
        for(pair<int, int> dir : dirs) {
            init.first += dir.first; init.second += dir.second;
            swap(table[init.first][init.second], cur);
            temp.push_back(cur);
        }
        answer.push_back(*min_element(temp.begin(), temp.end()));
    }
    
    return answer;
}