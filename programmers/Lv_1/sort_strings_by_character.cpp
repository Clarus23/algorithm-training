#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<char> character;
    
    for(string s: strings) {
        character.push_back(s[n]);
    }
    
    for(int i=strings.size(); i>0; i--) {
        for(int j=0; j<i-1; j++) {
            if(character[j] > character[j+1]) {
                swap(character[j], character[j+1]);
                swap(strings[j], strings[j+1]);
            } else if(character[j] == character[j+1] && strings[j].compare(strings[j+1]) > 0) {
                swap(character[j], character[j+1]);
                swap(strings[j], strings[j+1]);
            } else continue;
        }
    }
    
    answer.swap(strings);
    return answer;
}