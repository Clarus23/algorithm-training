#include <string>
#include <regex>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int point[3];
    
    regex reg("(([0-9]+)(S|D|T)(\\*|#)*)");
    regex pointReg("([0-9]+)");
    regex bonusReg("(S|D|T)");
    smatch match;

    for(int i=0; i<3; i++) {
        regex_search(dartResult, match, reg);
        string curDart = match.str();
        dartResult = match.suffix();
        
        regex_search(curDart, match, pointReg);
        point[i] = stoi(match.str());
        curDart = match.suffix();
        
        char bonus = ' ', option = ' ';
        regex_search(curDart, match, bonusReg);
        bonus = match.str()[0];
        option = match.suffix().str()[0];
        
        if(bonus == 'D') point[i] = pow(point[i], 2);
        else if(bonus == 'T') point[i] = pow(point[i], 3);
        
        if(option == '*') {
            point[i] *= 2;
            if(i != 0) point[i-1] *= 2;
        } else if(option == '#') point[i] *= (-1);
    }
    
    answer = point[0]+point[1]+point[2];
    
    return answer;
}