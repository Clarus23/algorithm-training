#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, m;
    scanf("%d\n%d", &n, &m);
    vector<bool> isInfested(n, false);
    vector<vector<bool>> network(n, vector<bool>(n, false));

    int com1, com2;
    while(m--) {
        scanf("%d %d", &com1, &com2);
        network[com1-1][com2-1] = true;
        network[com2-1][com1-1] = true;
    }

    int top=-1;
    vector<int> stack(n);
    stack[++top] = 0;
    isInfested[0] = true;
    int infestedCom = 0, cur;
    while(top != -1) {
        cur = stack[top--];

        for(int i=1; i<n; i++) {
            if(network[cur][i] && !isInfested[i]) {
                stack[++top] = i;
                isInfested[i] = true;
                infestedCom++;
            }
        }
    }

    printf("%d", infestedCom);

    return 0;
}