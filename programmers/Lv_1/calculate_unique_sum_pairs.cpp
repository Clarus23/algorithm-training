#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> answerSet;
    for(int i=0; i<numbers.size(); i++) {
        for(int j=i+1; j<numbers.size(); j++) {
            answerSet.insert(numbers[i]+numbers[j]);
        }
    }
    for(set<int>::iterator iter = answerSet.begin(); iter!=answerSet.end(); iter++) answer.push_back(*iter);
    
    return answer;
}