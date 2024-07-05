#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
    int t; cin >> t;

    int n, m;
    while(t--) {
        cin >> n >> m;
        int* priorityArr = new int[n];
        queue<pair<int, int>> q;
        int priority;
        for(int i=0; i<n; i++) {
            cin >> priority;
            priorityArr[i] = priority;
            q.push({i, priority});
        } sort(priorityArr, priorityArr+n, greater<>());

        int cnt=0;
        while(true) {
            pair<int, int> temp = q.front(); q.pop();
            if(temp.second != priorityArr[cnt]) {
                q.push(temp);
                continue;
            }

            cnt++;
            if(temp.first == m) {
                cout << cnt << '\n';
                break;
            }
        }
    }
    return 0;
}