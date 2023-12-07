#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {  
    queue<pair<int,int>> bridge;
    
    bridge.push({truck_weights[0], bridge_length+1});
    weight -= truck_weights[0];
    
    int time=2; int cnt=1;
    while(cnt < truck_weights.size()) {
        if(time == bridge.front().second) {
            weight += bridge.front().first;
            bridge.pop();
        }
        
        int truck = truck_weights[cnt];   
        if(weight < truck) {
            time = bridge.front().second;
            continue;
        }
        
        weight -= truck;
        bridge.push({truck, time+bridge_length});
        
        cnt++;
        time++;
    }
    
    
    return bridge.back().second;
}