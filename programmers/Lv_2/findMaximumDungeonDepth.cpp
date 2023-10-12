#include <string>
#include <vector>

using namespace std;

void dfs(vector<bool> visited, vector<vector<int>> dungeons, int h, vector<int> stack, int* candidate) {
    if(h == dungeons.size()) {
        *candidate = (stack.size()-1 > *candidate) ? stack.size()-1 : *candidate;
        return;
    }
    
    for(int i=0; i<dungeons.size(); i++) {
        if(visited[i]) continue;
        
        int curFatigue = stack.back();
        visited[i] = true;
        if(curFatigue < dungeons[i][0]) dfs(visited, dungeons, h+1, stack, candidate);
        else {
            stack.push_back(curFatigue-dungeons[i][1]);
            dfs(visited, dungeons, h+1, stack, candidate);
            stack.pop_back();
        }
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size());
    vector<int> stack(1, k);
    
    dfs(visited, dungeons, 0, stack, &answer);
    
    return answer;
}