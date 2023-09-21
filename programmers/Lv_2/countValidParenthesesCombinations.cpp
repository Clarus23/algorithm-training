#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<char> stack;
    
    int size = s.size();
    for(int i=0; i<size; i++) {
        bool flag = true;
        for(int j=0; j<size; j++) {
            char c = s[(i+j)%size];
            if(c=='(' || c=='{' || c=='[') stack.push_back(c);
            else if(stack.empty()) {
                flag = false;
                break;
            } else {
                char prevC = stack.back();
                if(c==')' && prevC=='(' 
                   || c=='}' && prevC=='{' 
                   || c==']' && prevC=='[') stack.pop_back();
                else {
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag && stack.empty()) answer++;
        else vector<char>().swap(stack);
    }
    
    return answer;
}