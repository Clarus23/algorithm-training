#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long number : numbers) {
        // 맨 뒤의 두 bit가 00, 01, 10일 경우 (각각, mod 4 연산시 값 : 0, 1, 2)
        // +1을 했을 때의 bit는 각각 01, 10, 11로
        // bit를 1~2개만 변환해서 +1 시키는게 가능함.
        if(number%4 != 3) {
            answer.push_back(number+1);
            continue;
        }
        
        // 뒤부터 봤을때 맨 처음으로 나오는 0bit를 1bit로 변환 후, 그 다음 1bit 를 0bit로 변환.
        // 즉, 뒤에서 처음으로 나오는 0의 맨 뒤부터의 거리를 i라고 했을때,
        // 현재 number + 2^(i-1)
        for(int i=2; ;i++) {
            // number의 bit를 맨 오른쪽에서 세번째 부터 한칸씩 왼쪽으로 이동하며 0인 bit를 찾음.
            // 세번째 부터인 이유 : 여기에 들어오는 모든 수는 bit가 ...11로 끝나기 때문.
            if(!((number >> i) & 1)) {
                answer.push_back(number + pow(2, i-1));
                break;
            }
        }
    }
    
    return answer;
}