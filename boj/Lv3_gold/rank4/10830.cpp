#include <iostream>
#include <vector>
using namespace std;

const int DIVISOR = 1000;

void mulMatrix(vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int size = matrix1.size();
    vector<vector<int>> temp(size, vector<int>(size, 0));

    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++) {
            for(int k=0; k<size; k++)
                temp[i][j] += (matrix1[i][k] * matrix2[k][j]);
            temp[i][j] %= DIVISOR;
        }

    matrix1.swap(temp);
}

int main() {
    int n; long long b;
    scanf("%d %lld", &n, &b);


    vector<vector<int>> answer(n, vector<int>(n, 0));
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) scanf("%d", &matrix[i][j]);
        answer[i][i] = 1;
    }

    while(b > 0) {
        if(b%2) mulMatrix(answer, matrix);
        mulMatrix(matrix, matrix);

        b/=2;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) printf("%d ", answer[i][j]);
        printf("\n");
    }

    return 0;
}