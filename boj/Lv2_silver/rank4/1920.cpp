#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int n; scanf("%d", &n);
    int* numbers = new int[n];
    for(int i=0; i<n; i++) scanf("%d", numbers+i);
    sort(numbers, numbers+n);

    int m, target; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &target);
        printf("%d\n", binary_search(numbers, numbers+n, target));
    }

    delete []numbers;
    return 0;
}