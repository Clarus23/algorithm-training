#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd, lcm;
    
    int max = (n>m) ? n : m;
    int min = (n<=m) ? n : m;
    int mod = max % min;
    while(mod) {
        max = min;
        min = mod;
        mod = max%min;
    }
    gcd = min;
    lcm = n*m/gcd;
    
    answer.push_back(gcd);
    answer.push_back(lcm);
    return answer;
}