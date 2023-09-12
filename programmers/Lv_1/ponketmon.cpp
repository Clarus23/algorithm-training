#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<bool> ponketmon(200000, false);
    int type=0;
    
    for(int it: nums) {
        if(!ponketmon[it]) {
            ponketmon[it] = true;
            type++;
        }
    }
    
    answer = (nums.size()/2>type) ? type : nums.size()/2;
    
    return answer;
}