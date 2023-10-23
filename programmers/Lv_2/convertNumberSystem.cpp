#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string baseChange(int n, int k) {
    if(!n) return "0";
    
    string result = "";
    while(n) {
        if(n%k<10) result += (char)(n%k+'0');
        else result += (char)((n%k-10)+'A');
        n /= k;
    }
    reverse(result.begin(), result.end());
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int num = 0; // 전단계의 lastOrder;
    int lastOrder = n;
    int digit=1; // 자리수
    for(int order=0; answer.size()<t; order++) {
        if(order == lastOrder) {
            digit++;
            num = order;
            lastOrder += (digit * (n-1) * pow(n, digit-1)); 
        }
        
        if(order%m == p-1) {
            int targetNum = (order-num)/digit;
            if(digit != 1) targetNum += pow(n, digit-1);
            string target = (n==10) ? to_string(targetNum) : baseChange(targetNum, n);
            
            answer += target[(order-num)%digit];
        }
    }
    
    return answer;
}