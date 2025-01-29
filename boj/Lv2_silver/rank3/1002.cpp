#include <iostream>
using namespace std;

int pow(int num) { return num*num; }
int powDistance(int x1, int x2, int y1, int y2) { return pow(x1-x2)+pow(y1-y2); }

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        if(x1==x2 && y1==y2 && r1==r2) printf("-1\n");
        else if(powDistance(x1, x2, y1, y2) > pow(r1+r2) ||
                powDistance(x1, x2, y1, y2) < pow(r1-r2)) printf("0\n");
        else if(powDistance(x1, x2, y1, y2) == pow(r1+r2) ||
                powDistance(x1, x2, y1, y2) == pow(r1-r2)) printf("1\n");
        else printf("2\n");
    }

    return 0;
}