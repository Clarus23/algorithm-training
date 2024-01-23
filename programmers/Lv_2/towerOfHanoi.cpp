#include <string>
#include <vector>

using namespace std;

void hanoiFunc(int n, int s, int t, int g, vector<vector<int>>& answer) {
    if(n==1) {
        answer.push_back({s, g});
        return;
    }
    
    hanoiFunc(n-1, s, g, t, answer);
    answer.push_back({s, g});
    hanoiFunc(n-1, t, s, g, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoiFunc(n, 1, 2, 3, answer);
    return answer;
}