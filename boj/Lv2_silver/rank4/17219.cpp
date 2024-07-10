#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    map<string, string> passwords;
    while(n--) {
        char site[20], pwd[20];
        scanf("%s %s", site, pwd);
        passwords.insert({site, pwd});
    }

    while(m--) {
        char site[20];
        scanf("%s", site);

        for(int i=0; passwords[site][i] != '\0'; i++) printf("%c", passwords[site][i]);
        printf("\n");
    }

    return 0;
}