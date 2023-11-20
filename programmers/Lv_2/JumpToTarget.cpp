#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int solution(int x, int y, int n) {
    if(x == y) return 0;
    
    int answer = -1;
    queue<pair<int, int>> q;
    set<int> isAppear;
    
    q.push({x, 0});
    isAppear.insert(x);
    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur*3 == y || cur*2 == y || cur+n == y) {
            answer = cnt+1;
            break;
        }
        
        if(cur*3<y && isAppear.find(cur*3)==isAppear.end()) {
            q.push({cur*3, cnt+1});
            isAppear.insert(cur*3);
        }
        if(cur*2<y && isAppear.find(cur*2)==isAppear.end()) {
            q.push({cur*2, cnt+1});
            isAppear.insert(cur*2);
        }
        if(cur+n<y && isAppear.find(cur+n)==isAppear.end()) {
            q.push({cur+n, cnt+1});
            isAppear.insert(cur+n);
        }
    }
    
    return answer;
}