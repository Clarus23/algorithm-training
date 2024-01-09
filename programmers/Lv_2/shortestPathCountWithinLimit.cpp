#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    vector<vector<int>> wGraph(N, vector<int>(N, 0)); //가중치 그래프를 행렬로 표현.
    for(vector<int> it : road) {
        if(!wGraph[it[0]-1][it[1]-1] || it[2]<wGraph[it[0]-1][it[1]-1]) {
            wGraph[it[0]-1][it[1]-1] = it[2];
            wGraph[it[1]-1][it[0]-1] = it[2];
        }
    }
    
    vector<int> visited(N, -1);
    queue<int> q; //현재 위치를 가지고 있는 queue
    visited[0] = 0; q.push(0); //초기값 설정
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        int weight = visited[cur];
        
        for(int i=1; i<N; i++) {
            if(wGraph[cur][i] && weight+wGraph[cur][i] <= K
               && (visited[i] == -1 || weight+wGraph[cur][i] < visited[i])) {
                q.push(i);
                visited[i] = weight+wGraph[cur][i];
            }
        }
    }
    
    return count_if(visited.begin(), visited.end(), [](int time) {
        return (time != -1);
    });
}