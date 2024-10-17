#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<vector<int>> triangle(n, vector<int>(n, 0));

    scanf("%d", &triangle[0][0]);
    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            int input; scanf("%d", &input);

            if(j==0) input += triangle[i-1][0];
            else if(j==i) input += triangle[i-1][i-1];
            else input += max(triangle[i-1][j-1], triangle[i-1][j]);

            triangle[i][j] = input;
        }
    }
    printf("%d", *max_element(triangle[n-1].begin(), triangle[n-1].end()));

    return 0;
}