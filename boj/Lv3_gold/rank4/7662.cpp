#include <iostream>
#include <set>
using namespace std;

int main() {
    int test; scanf("%d", &test);
    while(test--) {
        int k; scanf("%d", &k);
        multiset<int> s;

        while(k--) {
            char op; int num;
            scanf(" %c %d", &op, &num);

            if(op == 'I') s.insert(num);
            else if(!s.empty()) {
                if(num == 1) s.erase(--s.end());
                else s.erase(s.begin());
            }
        }

        if(s.empty()) printf("EMPTY\n");
        else printf("%d %d\n", *(--s.end()), *s.begin());
    }
    return 0;
}