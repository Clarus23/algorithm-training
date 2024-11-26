#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<pair<int, int>> candyBar;

    int fruit = 0, ea = 0;
    for(int i=0; i<n; i++) {
        int curFruit; scanf("%d", &curFruit);
        if(curFruit == fruit) {
            ea++;
            continue;
        }

        candyBar.push_back({fruit, ea});
        fruit = curFruit;
        ea = 1;
    } candyBar.push_back({fruit, ea});

    int answer = 0;
    int pprevFruit=0, prevFruit=candyBar[1].first;
    int cnt=candyBar[1].second, prevCnt=candyBar[1].second;
    for(int i=2; i<candyBar.size(); i++) {
        if(candyBar[i].first != pprevFruit) {
            answer = (cnt > answer) ? cnt : answer;
            cnt = prevCnt + candyBar[i].second;
        } else cnt += candyBar[i].second;

        pprevFruit = prevFruit;
        prevFruit = candyBar[i].first;
        prevCnt = candyBar[i].second;
    } answer = (cnt > answer) ? cnt : answer;

    printf("%d", answer);

    return 0;
}