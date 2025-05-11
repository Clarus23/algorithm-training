#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int tc=0; tc<10; tc++) {
        int testNum; cin >> testNum;
        int ladder[100][100];
        for(auto& i : ladder) for(int& j : i) cin >> j;

        int col;
        for(int i=0; i<100; i++) {
            if(ladder[99][i] != 2) continue;

            col = i;
            break;
        }

        for(int row=99; row>0; row--) {
            if(col < 99 && ladder[row][col+1]) {
                while(col < 99 && ladder[row][col+1]) col++;
            } else if(col > 0 && ladder[row][col-1]) {
                while(col > 0 && ladder[row][col-1]) col--;
            }
        }

        cout << '#' << tc+1 << ' ' << col << '\n';
    }

    return 0;
}