#include <iostream>
#include <vector>
using namespace std;

int main() {
    int testCase; cin >> testCase;
    for(int t=1; t<=testCase; t++) {
        int n; cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> matrix[i][j];

        cout << '#' << t << '\n';
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=0; j--) cout << matrix[j][i];
            cout << ' ';
            for(int j=n-1; j>=0; j--) cout << matrix[n-1-i][j];
            cout << ' ';
            for(int j=0; j<n; j++) cout << matrix[j][n-1-i];
            cout << '\n';
        }
    }

    return 0;
}