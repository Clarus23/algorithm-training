#include <iostream>
#include <vector>
using namespace std;

/*
* # union - find, greedy
* ## greedy 적 관점 -> 내가 도킹할 수 있는 가장 큰 게이트에 도킹한다.
* ## union - find => 현재 내가 도킹할 수 있는 가장 큰 게이트를 찾는다.
* ## union - find의 응용이 필요한 문제.
* ## "그룹의 대표" 가 아닌 "다음 도킹할 게이트" 라는 것에 주의해야함.
*
* # 메모리: 2412 kb
* # 실행시간: 8 ms
* # 체감난이도: 중상
*/

int find(vector<int>& gates, int x) {
    if (gates[x] < 0) return x;

    return (gates[x] = find(gates, gates[x]));
}

void merge(vector<int>& gates, int x, int y) {
    x = find(gates, x); y = find(gates, y);

    gates[x] = y;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int g, p;
    cin >> g >> p;

    int docking = 0;
    vector<int> gates(g+1, -1);
    while (p--) {
        int x; cin >> x;
        
        int gate = find(gates, x);
        
        if (gate == 0) break;
        
        ++docking;
        
        merge(gates, gate, gate - 1);
    }

    cout << docking;

    return 0;
}