#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int it : scoville) minHeap.push(it);
    
    int min1 = minHeap.top(); minHeap.pop();
    while(min1 < K) {
        if(minHeap.size() < 1) return -1;
        
        int min2 = minHeap.top(); minHeap.pop();
        minHeap.push(min1 + min2*2);
        answer++;
        
        min1 = minHeap.top(); minHeap.pop();
    }
    
    return answer;
}