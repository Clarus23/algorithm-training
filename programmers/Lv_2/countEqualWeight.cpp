#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, int> m;
    for(int weight : weights) m[weight]++;
    
    for(auto it=m.begin(); it!=m.end(); it++) {
        int weight = it->first;
        int cnt = it->second;
        
        answer += ((long long)cnt*(cnt-1)/2);   // 같은 거리의 경우(nC2)
        for(int i=1; i<=3; i++)                 // 각각 4:2((2/1)x=y), 3:2((3/2)x=y), 4:3((4/3)x=y) 거리의 경우
            if(!(weight%i) && m.find(weight*(i+1)/i) != m.end())
                answer += ((long long)cnt*m[weight*(i+1)/i]);
    }
    
    return answer;
}