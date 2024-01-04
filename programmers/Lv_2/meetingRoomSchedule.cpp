#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    if(book_time.size() == 1) return 1;
    vector<pair<int, int>> times;

    for(auto book : book_time) {
        int start = stoi(book[0].substr(0, 2))*60 + stoi(book[0].substr(3, 2));
        int end = stoi(book[1].substr(0, 2))*60 + stoi(book[1].substr(3, 2));

        times.push_back({start, end + 10});
    }
    sort(times.begin(), times.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first < b.first) return true;
        else if(a.first == b.first && a.second < b.second) return true;
        return false;
    });

    vector<int> room(1, 0);
    for(auto time : times) {  
        if(time.first >= room[0]) room[0] = time.second;
        else room.push_back(time.second);

        sort(room.begin(), room.end());
    }

    return room.size();
}