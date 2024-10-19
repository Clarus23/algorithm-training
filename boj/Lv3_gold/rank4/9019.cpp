#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int a, b; scanf("%d %d", &a, &b);

        vector<bool> isAppear(10000, false);
        queue<pair<int, string>> q;
        q.push({a, ""});
        isAppear[a] = true;
        while(!q.empty()) {
            int n = q.front().first;
            string ic = q.front().second;
            q.pop();

            bool flag = false;
            pair<int, char> dslr[4] = {{(2*n)%10000, 'D'}, {(n)?(n-1):9999, 'S'}, {(n%1000)*10 + (n/1000), 'L'}, {(n%10)*1000 + (n/10), 'R'}};
            for(pair<int, char>& next : dslr) {
                if(isAppear[next.first]) continue;

                if(next.first == b) {
                    printf("%s%c\n", ic.c_str(), next.second);
                    flag = true;
                    break;
                }

                q.push({next.first, ic+next.second});
                isAppear[next.first] = true;
            }
            if(flag) break;
        }
    }
}