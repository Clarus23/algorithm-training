#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    bool isExist[21] = {false, };

    int m; scanf("%d", &m);
    char op[10]; int element;
    while(m--) {
        scanf("%s", op);

        if(!strcmp(op, "all")) for(int i=1; i<21; i++) isExist[i] = true;
        else if(!strcmp(op, "empty")) for(int i=1; i<21; i++) isExist[i] = false;
        else if(!strcmp(op, "add")) {
            scanf("%d", &element);
            isExist[element] = true;
        } else if(!strcmp(op, "remove")) {
            scanf("%d", &element);
            isExist[element] = false;
        } else if(!strcmp(op, "check")) {
            scanf("%d", &element);
            printf("%d\n", isExist[element]);
        } else if(!strcmp(op, "toggle")) {
            scanf("%d", &element);
            isExist[element] = !isExist[element];
        }
    }

    return 0;
}