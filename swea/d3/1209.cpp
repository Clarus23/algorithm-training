#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int tc=0; tc<10; ++tc) {
        int arr[100][100];
        int testNum; cin >> testNum;

        for(auto& row : arr)
            for(int& square : row)
                cin >> square;

        int row[100] = {0, };
        int col[100] = {0, };
        int leftDiag = 0;
        int rightDiag = 0;
        for(int i=0; i<100; i++) {
            for(int j=0; j<100; j++) {
                row[i] += arr[i][j];
                col[i] += arr[j][i];
            }

            leftDiag += arr[i][i];
            rightDiag += arr[i][99-i];
        }

        cout << '#' << tc+1 << ' ' << max({leftDiag, rightDiag, *max_element(row, row+100), *max_element(col, col+100)}) <<'\n';
    }

    return 0;
}