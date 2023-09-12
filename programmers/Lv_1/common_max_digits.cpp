#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    bool onlyZero = true;
    
    sort(X.rbegin(), X.rend());
    sort(Y.rbegin(), Y.rend());
    
    int x=0; int y=0;
    while(x < X.size() && y < Y.size()) {
        if(X[x] == Y[y]) {
            if(onlyZero && X[x] != '0') onlyZero = false;
            answer += X[x];
            x++; y++;
        }
        else if(X[x] < Y[y]) y++;
        else if(X[x] > Y[y]) x++;
    }
    
    if(answer == "") answer = "-1";
    else if(onlyZero) answer = "0";
    
    return answer;
}