#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> closet;
    
    for(vector<string> cloth : clothes) {
        if(closet.find(cloth[1]) != closet.end()) closet[cloth[1]]++;
        else closet.insert({cloth[1], 1});
    }
    
    answer = 1; // 곱셈의 항등원.
    for(auto it = closet.begin(); it != closet.end(); it++)
        answer *= (it->second +1); // 한 종류에 있는 모든 아이템 수 + 1(이 종류를 선택하지 않았을 경우.)
    answer -= 1; // 모두 고르지 않았을 경우를 빼줌.
    
    return answer;
}