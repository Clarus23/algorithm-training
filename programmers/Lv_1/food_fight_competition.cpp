#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    vector<int> nums(1,1);
    
    for(int i=1; i<food.size(); i++) nums.push_back(food[i]/2);
    
    for(int i=1; i<nums.size(); i++) {
        for(int j=0; j<nums[i]; j++) {
            answer += to_string(i);
        }
    }
    string reverse = answer;
    sort(reverse.rbegin(), reverse.rend());
    answer += "0";
    answer += reverse;
    
    return answer;
}