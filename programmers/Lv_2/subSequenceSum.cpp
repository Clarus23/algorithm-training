#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);
    queue<pair<int, int>> subSequence; // 부분 수열의 {원소, 인덱스} 형태를 저장하는 Queue.
    
    int total=0; int length=1000000; // 부분 수열의 길이(length)와 원소의 합(total)을 저장할 변수.
    for(int index=0; index<sequence.size(); index++) {
        int num = sequence[index];
        if(num == k) return {index, index};
        
        total += num;
        subSequence.push({num, index});
        
        while(total > k) {
            total -= subSequence.front().first;
            subSequence.pop();
        }
        
        if(total == k && subSequence.size()-1 < length) {
            answer[0] = subSequence.front().second;
            answer[1] = index;
            length = answer[1] - answer[0];
        }
    }
    
    return answer;
}