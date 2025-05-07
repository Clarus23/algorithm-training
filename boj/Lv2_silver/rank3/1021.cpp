#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> dq;
    for(int i=1; i<=n; i++) dq.push_back(i);

    int answer = 0;
    for(int i=0; i<m; i++) {
        int target; cin >> target;

        int idx;
        for(int j=0; ; j++) {
            if (dq[j] == target) {
                idx = j;
                break;
            }
        }

        if(idx < dq.size()/2) {
            while(true) {
                if(dq.front() == target) {
                    dq.pop_front();
                    break;
                }

                dq.push_back(dq.front());
                dq.pop_front();
                answer++;
            }
        } else {
            while(true) {
                if(dq.front() == target) {
                    dq.pop_front();
                    break;
                }

                dq.push_front(dq.back());
                dq.pop_back();
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}