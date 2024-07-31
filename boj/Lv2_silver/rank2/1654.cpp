#include <iostream>
using namespace std;

int main(void) {
    int k, n;
    scanf("%d %d", &k, &n);
    unsigned int min = 1, max = 0, mid;
    unsigned int *lans = new unsigned int[k];
    for(int i=0; i<k; i++) {
        scanf("%d", lans+i);
        max = (lans[i] > max) ? lans[i] : max;
    }

    unsigned int candidate = 0;
    while(min <= max) {
        mid = (max+min)/2;

        unsigned int cnt = 0;
        for(int i=0; i<k; i++) cnt += (lans[i]/mid);

        if(cnt < n) max = mid-1;
        else {
            candidate = (mid > candidate) ? mid : candidate;
            min = mid+1;
        }
    } printf("%d", candidate);

    delete []lans;
    return 0;
}