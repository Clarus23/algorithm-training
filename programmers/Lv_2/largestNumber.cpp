#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    string ab = to_string(a)+to_string(b);
    string ba = to_string(b)+to_string(a);
    
    return ab > ba;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), comp);
    
    for(int number : numbers)
        if(answer != "" || number) answer += to_string(number);
    if(answer == "") return "0";
    
    return answer;
}