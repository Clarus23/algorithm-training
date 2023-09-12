#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int size = p.size();
    long long llP = stoll(p);
    
    for(int i=0; i<t.size(); i++) {
        if(stoll(t.substr(i,size)) <= llP && t.size()-i >= size) answer++;
    }
    
    return answer;
}