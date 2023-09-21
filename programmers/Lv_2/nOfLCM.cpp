#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int max = (a>b) ? a : b;
    int min = (a<=b) ? a : b;
    
    while(min) {
        int temp = min;
        min = max%min;
        max = temp;
    }
    
    return max;
}

int lcm(int a, int b) {
    return a*b/gcd(a,b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    while(true) {
        if(arr.size() == 1) {
            answer = arr[0];
            break;
        }
        
        vector<int> temp;
        for(int i=0; i<arr.size(); i+=2) {
            if(i == arr.size()-1) temp.push_back(arr[i]);
            else temp.push_back(lcm(arr[i], arr[i+1]));
        }
        
        arr.swap(temp);
    }
    
    return answer;
}