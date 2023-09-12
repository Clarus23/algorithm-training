#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    const int size = survey.size();
    map<char, int> category;
    
    string categoryInsert = "RTCFJMAN";
    for(char c : categoryInsert) category.insert({c, 0});
    
    for(int i=0; i<size; i++) {
        char negative = survey[i][0];
        char positive = survey[i][1];
        
        int point = choices[i] - 4;
        if(point < 0) category[negative] += ((-1)*point);
        else if(point > 0) category[positive] += point;
    }
    
    answer += ((category['R'] >= category['T']) ? 'R' : 'T');
    answer += ((category['C'] >= category['F']) ? 'C' : 'F');
    answer += ((category['J'] >= category['M']) ? 'J' : 'M');
    answer += ((category['A'] >= category['N']) ? 'A' : 'N');
    
    return answer;
}