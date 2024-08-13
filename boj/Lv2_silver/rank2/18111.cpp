#include <iostream>
#include <map>
#include <climits>
using namespace std;

int main(void) {
    int n, m, b;
    scanf("%d %d %d", &n, &m, &b);
    map<int, int> plat;

    pair<int, int> minMax = {INT_MAX, 0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int h; scanf("%d", &h);
            plat[h]++;

            minMax.first = (h < minMax.first) ? h : minMax.first;
            minMax.second = (h > minMax.second) ? h : minMax.second;
        }
    }

    pair<int, int> answer = {INT_MAX, 0};
    for(int height=minMax.first; height<=minMax.second; height++) {
        int blocks = b;
        int time = 0;
        for(auto it : plat) {
            if(height == it.first) continue;

            if(height < it.first) {
                time += (it.second * (it.first-height)*2);
                blocks += (it.second * (it.first-height));
            } else {
                time += (it.second * (height-it.first));
                blocks -= (it.second * (height-it.first));
            }
        } if(blocks < 0 || time > answer.first) continue;

        answer.first = (time < answer.first) ? time : answer.first;
        answer.second = (time == answer.first && height > answer.second) ? height : answer.second;
    } printf("%d %d", answer.first, answer.second);

    return 0;
}