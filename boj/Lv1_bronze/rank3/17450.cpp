#include <iostream>
using namespace std;

int main(void) {
    pair<int, int> s, n, u;
    scanf("%d %d", &s.first, &s.second);
    scanf("%d %d", &n.first, &n.second);
    scanf("%d %d", &u.first, &u.second);

    double sCE = (s.first*10 < 5000) ? ((double)s.second/s.first) : ((double)s.second*10/(s.first*10-500));
    double nCE = (n.first*10 < 5000) ? ((double)n.second/n.first) : ((double)n.second*10/(n.first*10-500));
    double uCE = (u.first*10 < 5000) ? ((double)u.second/u.first) : ((double)u.second*10/(u.first*10-500));

    if(sCE > nCE && sCE > uCE) printf("S");
    else if(nCE > sCE && nCE > uCE) printf("N");
    else if(uCE > sCE && uCE > nCE) printf("U");

    return 0;
}