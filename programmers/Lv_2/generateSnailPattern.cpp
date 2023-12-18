#include <string>
#include <vector>

using namespace std;

void makeSnail(vector<vector<int>>& snail, int n, int tri, int number) {
    for(int i=0; i<n; i++) snail[tri*2 + i][tri] = number++; // tri번째 삼각형의 첫번째 선분
    for(int i=0; i<n-1; i++) snail[tri*2 + n-1][tri+1 + i] = number++; // tri번째 삼각형의 두번째 선분
    for(int i=0; i<n-2; i++) snail[tri*2 + n-2 - i][tri + n-2 - i] = number++; // tri번째 삼각형의 세번째 선분
    
    if(n<1) return;
    makeSnail(snail, n-3, tri+1, number);
}


vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail(n, vector<int>(n, 0));
    
    makeSnail(snail, n, 0, 1);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<i+1; j++)
            answer.push_back(snail[i][j]);
    
    return answer;
}