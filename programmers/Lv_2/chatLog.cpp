#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> nicknameMap;
    vector<pair<string, string>> messages;
    
    for(string s : record) {
        stringstream ss(s);
        string op, uid, nickname;
        ss >> op >> uid >> nickname;
        
        if(op == "Enter") {
            messages.push_back({uid, "님이 들어왔습니다."});
            nicknameMap[uid] = nickname;
        }
        else if(op == "Leave") messages.push_back({uid, "님이 나갔습니다."});
        else nicknameMap[uid] = nickname;
    }
    
    for(pair<string, string> message : messages)
        answer.push_back(nicknameMap[message.first] + message.second);
    
    return answer;
}