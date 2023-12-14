#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    const int size = queue1.size();
    
    long long q1Sum=0;
    long long q2Sum=0;
    for(int i=0; i<size; i++) {
        q1Sum += queue1[i];
        q2Sum += queue2[i];
    }
    
    int top1=0;
    int top2=0;
    while(q1Sum != q2Sum) {
        if(top1 >= size && top2 >= size) return -1;
        
        if(q1Sum > q2Sum) {
            queue2.push_back(queue1[top1]);
            q1Sum -= queue1[top1];
            q2Sum += queue1[top1];
            top1++;
        } else {
            queue1.push_back(queue2[top2]);
            q1Sum += queue2[top2];
            q2Sum -= queue2[top2];
            top2++;
        }
        
        answer++;
    }
    
    return answer;
}