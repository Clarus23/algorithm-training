#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> numbers;
    
    do {
        numbers.push_back(stoi(s.substr(0,s.find(' '))));
        s = s.substr(s.find(' ')+1);
    } while(s.find(' ') != string::npos);
    numbers.push_back(stoi(s));
    
    sort(numbers.begin(), numbers.end());
    
    answer = to_string(numbers[0]) + " " + to_string(numbers.back());
    
    return answer;
}