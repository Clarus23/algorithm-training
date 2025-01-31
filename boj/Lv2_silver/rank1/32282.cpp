#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);

    double distance = sqrt(x*x+y*y)/c;

    if(x==0 && y==0) printf("0");
    else if(distance < 1) printf("2");
    else printf("%d", (int)ceil(distance));

    return 0;
}