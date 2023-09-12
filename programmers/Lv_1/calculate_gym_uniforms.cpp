#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> trainingSuit(n, 1);
    
    for(int it : reserve) trainingSuit[it-1]++;
    for(int it : lost) trainingSuit[it-1]--;
    
    for(int i=0; i<n; i++) {
        if(trainingSuit[i] == 0) {
            if(i == 0) {
                if(trainingSuit[i+1] == 2) {
                    trainingSuit[i] = 1;
                    trainingSuit[i+1] = 1;
                }
            } else if(i == n-1) {
                if(trainingSuit[i-1] == 2) {
                    trainingSuit[i] = 1;
                    trainingSuit[i-1] = 1;
                }
            } else {
                if(trainingSuit[i-1] == 2) {
                    trainingSuit[i] = 1;
                    trainingSuit[i-1] = 1;
                } else if(trainingSuit[i+1] == 2) {
                    trainingSuit[i] = 1;
                    trainingSuit[i+1] = 1;
                }
            }
        }
        
        if(trainingSuit[i] > 0) answer++;
    }
    
    return answer;
}