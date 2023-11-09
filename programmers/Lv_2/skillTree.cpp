#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int alpha[26] = {0,};
    
    int i=1;
    for(char c : skill) alpha[c-'A'] = i++;
    
    for(string skTree : skill_trees) {
        int i=1;
        bool possible = true;
        for(char sk : skTree) {
            if(alpha[sk-'A']) {
                if(alpha[sk-'A'] != i) {
                    possible = false;
                    break;
                }
                
                i++;
            }
        }
        if(possible) answer++;
    }
    
    return answer;
}