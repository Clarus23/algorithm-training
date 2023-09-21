#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string decToBin(int num) {
    string result = "";
    for(int i = 17; i>=0; i--) {
        //150,000은 2의 18승으로 표현이 가능하기때문에 i의 값을 이렇게 설정. 
        char temp = ((num >> i) & 1) + '0';
        
        if(result == "" && temp == '0') continue; //문자열이 1로 시작하게 제한.
        else result.push_back(temp);
    }
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt=0;
    int zeroCnt=0;
    while(true) {
        sort(s.begin(), s.end());
        zeroCnt += s.find("1"); //0의 개수
        int length = s.size() - s.find("1"); //1의 개수
        
        cnt++;
        
        if(length == 1) break;
        else s = decToBin(length);
    }
    
    answer.push_back(cnt);
    answer.push_back(zeroCnt);
    
    return answer;
}