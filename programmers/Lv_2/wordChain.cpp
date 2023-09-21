#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    set<string> wordSet;
    
    char lastChar = ' ';
    int prevSize = 0;
    int curSize;
    for(int i=0; i<words.size(); i++) {
        if(lastChar != ' ' && words[i][0] != lastChar) {
            answer[0] = i%n + 1;
            answer[1] = i/n + 1;
            break;
        }
        
        wordSet.insert(words[i]);
        lastChar = words[i][words[i].size()-1];
        curSize = wordSet.size();
        
        if(curSize == prevSize) {
            answer[0] = i%n + 1;
            answer[1] = i/n + 1;
            break;
        }
        prevSize = curSize;
    }

    return answer;
}