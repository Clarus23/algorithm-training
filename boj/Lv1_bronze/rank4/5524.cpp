#include <iostream>

int main(void) {
    int n; scanf("%d", &n);
    while(n--) {
        char str[20];
        scanf("%s", str);

        for(int i=0; str[i]!='\0'; i++) {
            if(str[i] >= 'A' && str[i] <= 'Z') printf("%c", str[i]-'A'+'a');
            else printf("%c", str[i]);
        } printf("\n");
    }

    return 0;
}