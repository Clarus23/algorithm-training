#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    /**
    * 만약 n이 3이라면, 결과는
    * 1 2 3 2 2 3 3 3 3 이 된다.
    * n개 단위로 잘라보면 (step 1: 1,2,3) (step 2: 2,2,3) (step 3: 3,3,3) 이고,
    * 이는 step에 따라 step보다 작은 수는 step의 값으로 치환된것과 같다.
    */
    for(long long i=left; i<=right; i++) {
        int step = (i/n) + 1;
        int value = i%n+1;
        
        answer.push_back((step > value) ? step : value);
    }
    
    return answer;
}