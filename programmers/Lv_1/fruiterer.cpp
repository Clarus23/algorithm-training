#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    
    while(!score.empty() && score.size() >= m) {
        int minScore = score.back(); score.pop_back();
        for(int i=1; i<m; i++) {
            minScore = min(minScore, score.back());
            score.pop_back();
        }
        answer += (minScore * m);
    }
    
    return answer;
}