#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    vector<int> stack;
    
    stack.push_back(numbers[numbers.size()-1]);
    for(int i=numbers.size()-2; i>=0; i--) {
        while(!stack.empty()) {
            int top=stack.back(); stack.pop_back();
            if(top > numbers[i]) {
                answer[i] = top;
                stack.push_back(top);
                break;
            }
        }
        stack.push_back(numbers[i]);
    }
    
    return answer;
}