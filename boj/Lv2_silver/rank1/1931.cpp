#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n; scanf("%d", &n);
    vector<pair<unsigned int, unsigned int>> meetings(n);
    for(int i=0; i<n; i++) scanf("%d %d", &meetings[i].first, &meetings[i].second);
    sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
        return (a.second < b.second) || (a.second == b.second && a.first < b.first);
    });

    unsigned int cur=0, cnt=0;
    for(pair<unsigned int, unsigned int>& meeting : meetings) {
        if(meeting.first < cur) continue;

        cnt++;
        cur = meeting.second;
    } printf("%u", cnt);

    return 0;
}