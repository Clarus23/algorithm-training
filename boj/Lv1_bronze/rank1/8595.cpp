#include <iostream>

int main(void) {
    int n; scanf("%d", &n);
    char* str = new char[n];
    scanf("%s", str);

    int hidden = 0;
    long long hiddenSum = 0;
    for(int i=0; i<n; i++) {
        if(str[i] < '0' || str[i] > '9') continue;

        hidden *= 10;
        hidden += (str[i]-'0');
        if(str[i+1] < '0' || str[i+1] > '9') {
            hiddenSum += hidden;
            hidden = 0;
        }
    }
    printf("%lld", hiddenSum);

    delete []str;
    return 0;
}