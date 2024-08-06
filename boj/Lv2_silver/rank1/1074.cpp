#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);

    int cnt=0, num = pow(2, 2*n);
    int rowStart = 0, rowEnd = pow(2, n);
    int colStart = 0, colEnd = pow(2, n);
    while(rowEnd - rowStart > 1) {
        int rowMid = (rowStart+rowEnd)/2;
        int colMid = (colStart+colEnd)/2;

        int temp = 0;
        if(r >= rowMid) {
            rowStart = rowMid;
            temp += 2;
        } else rowEnd = rowMid;
        if(c >= colMid) {
            colStart = colMid;
            temp += 1;
        } else colEnd = colMid;

        num /= 4;
        cnt += (num*temp);
    } printf("%d", cnt);

    return 0;
}