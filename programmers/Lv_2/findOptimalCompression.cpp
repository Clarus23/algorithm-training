#include <string>

using namespace std;

int solution(string s) {
    int maxCompressed = 0;
    for(int unit=1; unit<=s.size()/2; unit++) {
        string target = s.substr(0, unit);
        int compressed=0; int cnt=0;
        for(int i=unit; i<s.size(); i+=unit) {
            string cur = s.substr(i, unit);
            
            if(cur == target) { cnt++; continue; }
            
            target = cur;
            if(!cnt) continue;
            
            compressed += (unit*cnt - to_string(cnt+1).size());
            cnt = 0;
        } if(cnt) compressed += (unit*cnt - to_string(cnt+1).size());
        maxCompressed = (compressed > maxCompressed) ? compressed : maxCompressed;
    }
    
    return s.size()-maxCompressed;
}