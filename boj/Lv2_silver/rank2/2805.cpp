#include <iostream>
using namespace std;

int main(void) {
    unsigned int n, m;
    scanf("%d %d", &n, &m);

    unsigned int min = 1, max = 0, mid;
    unsigned int *trees = new unsigned int[n];
    for(int i=0; i<n; i++) {
        scanf("%d", trees+i);
        max = (trees[i] > max) ? trees[i] : max;
    }

    unsigned int candidate = 0;
    while(min <= max) {
        long long wood = 0;
        mid = (max+min)/2;
        for(int i=0; i<n; i++) if(mid < trees[i]) wood += (trees[i] - mid);

        if(wood == m) {
            candidate = mid;
            break;
        } else if(wood > m) {
            candidate = (mid > candidate) ? mid : candidate;
            min = mid+1;
        } else max = mid-1;
    } printf("%d", candidate);

    delete []trees;
    return 0;
}