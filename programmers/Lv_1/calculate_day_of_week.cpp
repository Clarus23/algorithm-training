#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> month = {31,29,31,30,31,30,31,31,30,31,30,31};
    vector<string> week = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int day=b-1;
    
    for(int i=0; i<a-1; i++) {
        day += month[i];
    }
    
    answer = week[day%7];
    
    return answer;
}