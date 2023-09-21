#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.rbegin(), citations.rend());
    
    for(int i=0; i<citations.size(); i++) {
        if(citations[i] < i+1) return i;
    }
    
    return citations.size();
}