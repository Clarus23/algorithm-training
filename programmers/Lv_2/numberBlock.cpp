#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(long long i=begin; i<=end; i++) {
        if(i==1) { answer.push_back(0); continue; }
        
        int max=1; bool flag=true;
        for(int j=2; (long long)j*j<=i; j++) {
            if(!(i%j)) {
                if(i/j <= 10000000) {
                    answer.push_back(i/j);
                    flag=false; break;
                }
                max = j;
            }
        }
        if(flag) answer.push_back(max);
    }
    
    return answer;
}