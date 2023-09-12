#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    regex reg("(aya|ye|woo|ma)*");
    regex regreg("(aya|ye|woo|ma)*(ayaaya|yeye|woowoo|mama)(aya|ye|woo|ma)*");
    
    for(string babble : babbling) {
        answer += regex_match(babble, reg);
        answer -= regex_match(babble, regreg);
    }
    
    return answer;
}