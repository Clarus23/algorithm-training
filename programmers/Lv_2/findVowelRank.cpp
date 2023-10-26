#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    int d[5] = {781, 156, 31, 6, 1};
    string s = "AEIOU";
    
    for(int i=0; i<word.size(); i++) answer += (1 + d[i]*s.find(word[i]));
    
    return answer;
}