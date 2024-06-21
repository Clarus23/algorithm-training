#include <cstdio>
#include <map>
using namespace std;

int main(void) {
    map<int, int> cards;
    int n, num; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &num);
        cards[num]++;
    }

    int m; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &num);
        printf("%d ", cards[num]);
    }

    return 0;
}