#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    vector<string> wantArr;
    
    for(int i=0; i<want.size(); i++) {
        for(int j=0; j<number[i]; j++) wantArr.push_back(want[i]);
    }
    sort(wantArr.begin(), wantArr.end());
    
    for(int i=0; i<discount.size()-9; i++) {
        vector<string> discount10(discount.begin()+i, discount.begin()+i+10);
        sort(discount10.begin(), discount10.end());
        
        if(wantArr == discount10) answer++;
        
        vector<string>().swap(discount10);
    }
    
    return answer;
}