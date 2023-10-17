#include <string>
#include <vector>
#include <regex>

using namespace std;

string notationChange(int n, int k) {
    string result = "";
    while(n) {
        result = (char)(n%k+'0') + result;
        n /= k;
    }
    return result;
}

bool isPrime(long long n) {
    if(n==1) return false;
    
    for(long long i=2; i*i<=n; i++)
        if(!(n%i)) return false;
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string str = (k==10) ? to_string(n) : notationChange(n, k);
    
    regex reg("0*([1-9]+)0*");
    smatch match;
    
    while(regex_search(str, match, reg)) {
        if(isPrime(stoll(match[1].str()))) answer++;
        str = match.suffix();
    }
    
    return answer;
}