#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<bool> walls(n, true);
    for(int i : section) walls[i-1] = false;
    
    for(int i=0; i<walls.size(); i++) {
        if(!walls[i] && i+m <= n) {
            for(int j=i; j<m+i; j++) walls[j] = true;
            answer++;
        } else if(!walls[i]) {
            for(int j=n-m; j<n; j++) walls[j] = true;
            answer++;
        }
    }
    
    return answer;
}