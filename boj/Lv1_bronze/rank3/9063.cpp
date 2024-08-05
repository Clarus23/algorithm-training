#include <iostream>
using namespace std;

int main(void) {
    int n; scanf("%d", &n);
    int minX = 10000, maxX = -10000;
    int minY = 10000, maxY = -10000;
    while(n--) {
        int x, y;
        scanf("%d %d", &x, &y);

        minX = (x < minX) ? x : minX;
        maxX = (x > maxX) ? x : maxX;
        minY = (y < minY) ? y : minY;
        maxY = (y > maxY) ? y : maxY;
    } printf("%d", (maxX-minX)*(maxY-minY));
    
    return 0;
}