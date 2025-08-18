#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for(int tc=1; tc<=t; ++tc) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> graph(n);
        vector<vector<int>> reverseGraph(n);
        for(int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            
            graph[a-1].push_back(b-1);
            reverseGraph[b-1].push_back(a-1);
        }
        
        int cnt = 0;
        for(int node=0; node<n; ++node) {
            vector<bool> isVisited(n, false);
            isVisited[node] = true;
            int num = 1;
            
            queue<int> q;
            q.push(node);
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                
                for(int next : graph[cur]) {
                    if(isVisited[next]) continue;
                    
                    isVisited[next] = true;
                    q.push(next);
                    ++num;
                }
            }
            
            q.push(node);
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                
                for(int next : reverseGraph[cur]) {
                    if(isVisited[next]) continue;
                    
                    isVisited[next] = true;
                    q.push(next);
                    ++num;
                }
            }
            
            if(num == n) ++cnt;
        }
        
        cout << "#" << tc << " " << cnt << "\n";
    }
    
    return 0;
}