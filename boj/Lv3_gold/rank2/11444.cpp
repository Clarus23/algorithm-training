#include <iostream>
using namespace std;

const int DIVISOR = 1000000007;

void mulMatrix(int (*matrix1)[2], const int (*matrix2)[2]) {
    int temp[2][2] = {0, 0, 0, 0};

    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
                temp[i][j] = (temp[i][j] + (long long)matrix1[i][k]*matrix2[k][j])%DIVISOR;

    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            matrix1[i][j] = temp[i][j];
}

int main() {
    int answer[2][2] = {1, 0, 0, 1};
    int matrix[2][2] = {1, 1, 1, 0};

    long long n; scanf("%lld", &n);

    while(n>0) {
        if(n%2) mulMatrix(answer, matrix);
        mulMatrix(matrix, matrix);

        n/=2;
    }

    printf("%d", answer[1][0]);

    return 0;
}