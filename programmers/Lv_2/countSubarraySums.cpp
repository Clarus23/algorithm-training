#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> answerSet;
    
    int size = elements.size();
    for(int i=0; i<size; i++) { //부분배열의 시작점
        int temp = 0;
        for(int j=0; j<size; j++) { //부분배열의 길이
            temp += elements[(i+j)%size];
            answerSet.insert(temp);
        }
    }
    
    answer = answerSet.size();
    
    return answer;
}