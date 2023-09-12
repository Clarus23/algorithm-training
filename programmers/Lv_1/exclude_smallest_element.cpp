#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size() == 1) answer.push_back(-1);
    else {
        int min = arr[0];
        for(int num : arr) min = (min > num) ? num : min;
        for(int num : arr) {
            if(num == min) continue;
            answer.push_back(num);
        }
    }
    
    return answer;
}