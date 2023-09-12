#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    string num = to_string(x);
    int div=0;
    for(char c: num) {
        div += (c-'0');
    }
    answer = (x%div == 0) ? true : false;
    
    return answer;
}