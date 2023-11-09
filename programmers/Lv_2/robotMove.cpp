#include <string>
#include <map>
#include <set>

using namespace std;

pair<int, int> operator+ (const pair<int, int>& x, const pair<int, int>& y) {
    return {x.first+y.first, x.second+y.second};
}

int solution(string dirs) {
    set<pair<pair<int, int>, pair<int, int>>> answerSet;
    map<char, pair<int, int>> dirMap = {
        {'U', {0, 1}},
        {'D', {0, -1}},
        {'R', {1, 0}},
        {'L', {-1, 0}}
    };
    
    pair<int, int> prev = {0, 0};
    for(char dir : dirs) {
        pair<int, int> cur = prev+dirMap[dir];
        if(cur.first > 5 || cur.first < -5 || cur.second > 5 || cur.second < -5) continue;
        
        answerSet.insert({prev, cur}); // 아래 행과 똑같은 선분 (a, b)
        answerSet.insert({cur, prev}); // 위 행과 똑같은 선분 (b, a)
        prev = cur;
    }
    
    return answerSet.size()/2; // 같은 선분을 두번씩 넣었으니 마지막에 2로 나눠줌.
}