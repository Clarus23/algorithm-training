#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; scanf("%d\n%d", &n, &m);
    vector<char> str(m);
    for(int i=0; i<m; i++) scanf(" %c", &str[i]);
    int answer = 0;

    int cnt=0; bool isI;
    if(str[0] == 'I') {
        cnt++;
        isI = true;
    } else isI = false;

    for(int i=1; i<m; i++) {
        if(isI && str[i] == 'I' || !isI && str[i] == 'O') {
            if(cnt > n) answer += (cnt-n);
            cnt = 0;
        }

        if(str[i] == 'I') {
            cnt++;
            isI = true;
        } else isI = false;
    } if(cnt > n) answer += (cnt-n);

    printf("%d", answer);

    return 0;
}