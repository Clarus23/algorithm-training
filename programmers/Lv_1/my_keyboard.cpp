#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int alphabet[26] = {0,};
    
    for(string key : keymap) {
        for(int i=0; i<key.size(); i++) {
            if(alphabet[key[i]-'A'] == 0 || (i+1 < alphabet[key[i]-'A']))
                alphabet[key[i]-'A'] = i+1;
        }
    }
    
    for(string target : targets) {
        answer.push_back(0);
        for(char c : target) {
            if(alphabet[c-'A'] == 0) {
                answer.back() = -1;
                break;
            } else answer.back() += alphabet[c-'A'];
        }
    }
    
    return answer;
}