#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int idx, vector<int>& answer, const vector<vector<char>>& matrix) {
    int sum = 0;

    for(int i=idx; i>=0; i--) {
        sum += answer[i];

        if(!(sum > 0 && matrix[i][idx] == '+'
        || sum == 0 && matrix[i][idx] == '0'
        || sum < 0 && matrix[i][idx] == '-')) {
            return false;
        }
    }
    return true;
}

bool dfs(int idx, vector<int>& answer, const vector<vector<char>>& matrix, const int& n) {
    if(idx == n-1) return true;

    for(int i=-10; i<=10; i++) {
        answer[++idx] = i;

        if(isPossible(idx, answer, matrix))
            if(dfs(idx, answer, matrix, n))
                return true;

        idx--;
    }

    return false;
}

int main() {
    int n; scanf("%d", &n);
    vector<vector<char>> matrix(n, vector<char>(n, ' '));
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            scanf(" %c", &matrix[i][j]);

    vector<int> answer(n, 0);
    dfs(-1, answer, matrix, n);
    for(int num : answer) printf("%d ", num);

    return 0;
}