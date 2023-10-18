#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<string, int> dictionary;
    int index;
    for(index=1; index<27; index++) dictionary.insert({alphabet.substr(index-1,1), index});

    for(int i=0; i<msg.size();) {
        string w = "";
        string nextW = w + msg[i];
        
        while(i<msg.size() && dictionary.find(nextW) != dictionary.end()) {
            w = nextW;
            nextW += msg[++i];
        }
        
        answer.push_back(dictionary[w]);
        dictionary.insert({nextW, index++});
    }

    return answer;
}