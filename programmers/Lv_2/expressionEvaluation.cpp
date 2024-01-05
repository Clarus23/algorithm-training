#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    string opPriority[6] = {"+-*", "+*-", "-+*", "-*+", "*+-", "*-+"};
    vector<pair<long long, char>> expressionV;
    
    string temp="";
    for(char c : expression) {
        if(c == '+' || c == '-' || c == '*') {
            expressionV.push_back({stoll(temp), c});
            temp="";
        } else temp += c;
    } expressionV.push_back({stoll(temp), ' '});
    
    for(string ops : opPriority) {
        vector<pair<long long, char>> exp(expressionV);
        for(char op : ops) {
            for(int i=0; i<exp.size(); i++) {
                if(exp[i].second == op) {
                    if(op == '+') exp[i].first += exp[i+1].first;
                    else if(op == '-') exp[i].first -= exp[i+1].first;
                    else exp[i].first *= exp[i+1].first;
                    exp[i].second = exp[i+1].second;
                    exp.erase(exp.begin()+((i--)+1));
                }
            }
        }
        
        answer = (abs(exp[0].first) > answer) ? abs(exp[0].first) : answer;
    }
    
    return answer;
}