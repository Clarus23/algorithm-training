#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    /**
    * 행렬곱 : A(m * x) * B(x * n) = AB(m * n)
    */
    int m = arr1.size();
    int n = arr2[0].size();
    int x = arr2.size();
    
    for(int i=0; i<m; i++) {
        vector<int> tempRow;
        for(int j=0; j<n; j++) {
            int temp = 0;
            for(int k=0; k<x; k++) temp += (arr1[i][k] * arr2[k][j]);
            tempRow.push_back(temp);
        }
        answer.push_back(tempRow);
    }
    
    return answer;
}