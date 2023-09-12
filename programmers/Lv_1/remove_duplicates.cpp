#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for(int it: arr) {
        if(answer.empty() || answer.back() != it) answer.push_back(it);
        else continue;
    }

    return answer;
}