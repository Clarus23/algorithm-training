#include <string>
#include <vector>
#include <queue>

using namespace std;

int subCount(vector<vector<bool>> graph, queue<int>& q) {
    int cnt=1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i=0; i<graph.size(); i++) {
            if(!graph[cur][i]) continue;
            
            graph[cur][i] = false; graph[i][cur] = false;
            q.push(i); cnt++;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for(vector<int> wire : wires) {
        graph[wire[0]-1][wire[1]-1] = true;
        graph[wire[1]-1][wire[0]-1] = true;
    }
    
    queue<int> q; int min = n;
    for(vector<int> wire : wires) {
        // 전선 끊기
        graph[wire[0]-1][wire[1]-1] = false;
        graph[wire[1]-1][wire[0]-1] = false;
        
        q.push(wire[0]-1);
        int sub1 = subCount(graph, q);
        min = (abs(2*sub1-n) < min) ? abs(2*sub1-n) : min; //if) sub2 == n-sub1 => sub1 - sub2 == 2*sub1 - n
        if(!min) return 0; // 두 subNetwork의 node 수가 동일한 경우 바로 종료.
        
        // 끊었던 전선 다시 회복
        graph[wire[0]-1][wire[1]-1] = true;
        graph[wire[1]-1][wire[0]-1] = true;
    }
    
    return min;
}