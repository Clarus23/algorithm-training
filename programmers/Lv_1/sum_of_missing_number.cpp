#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    int a=0;
    for(int i=0; i<10; i++) {
        if(numbers[a] == i) a++;
        else answer += i;
    }
    
    return answer;
}