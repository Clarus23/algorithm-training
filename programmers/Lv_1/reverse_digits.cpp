#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string strN = to_string(n);
    
    for(int i=strN.length()-1; i>=0; i--) {
        answer.push_back(strN[i]-'0');
    }
    
    return answer;
}