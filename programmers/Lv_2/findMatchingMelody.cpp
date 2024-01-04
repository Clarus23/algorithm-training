#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    while(m.find('#') != string::npos) { //반올림된 음은 소문자로 표현
        int id = m.find('#');
        m[id-1] += 32; m.erase(id, 1);
    }
    
    vector<pair<int, string>> candidate;
    for(string musicinfo : musicinfos) {
        istringstream ss(musicinfo); string subs;
        vector<string> info; //0:시작시간, 1:종료시간, 2:제목, 3:악보
        while(getline(ss, subs, ',')) info.push_back(subs);
        
        while(info[3].find('#') != string::npos) { //반올림된 음은 소문자로 표현
            int id = info[3].find('#');
            info[3][id-1] += 32; info[3].erase(id, 1);
        }
        
        int playingTime = (stoi(info[1].substr(0,2)) - stoi(info[0].substr(0,2)))*60
                        + (stoi(info[1].substr(3)) - stoi(info[0].substr(3)));
        string playingMelody = "";
        for(int i=0; i<playingTime; i++) playingMelody += info[3][i%info[3].size()];
        
        if(playingMelody.find(m) != string::npos) candidate.push_back({playingTime, info[2]});
    }
    
    stable_sort(candidate.begin(), candidate.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        if(a.first > b.first) return true;
        return false;
    });
    
    return (candidate.empty()) ? "(None)" : candidate[0].second;
}