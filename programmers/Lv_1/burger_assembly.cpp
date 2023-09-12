#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int hamburger[5] = {0,};
    bool flag=true;
    vector<int> stack;
    
    for(int it : ingredient) {
        if(stack.size() < 3) stack.push_back(it);
        else if(it ==2 || it == 3) stack.push_back(it);
        else {
            flag = true;
            hamburger[4] = 1;
            for(int i=3; i>0; i--) {
                hamburger[i] = stack.back();
                
                if(hamburger[i] == i) stack.pop_back();
                else {
                    stack.pop_back();
                    flag = false;
                }
            }
            if(flag) answer++;
            else {
                for(int i=1; i<5; i++) {
                    stack.push_back(hamburger[i]);
                    hamburger[i]=0;
                }
            }
        }
    }
    
    return answer;
}