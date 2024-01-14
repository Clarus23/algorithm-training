#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    vector<int> num(1, 1);              // num[n] = n+1
    vector<long long> facto(1, 1);      // facto[n] = (n+1)!
    for(int i=1; i<n; i++) {
        num.push_back(i+1);
        facto.push_back((i+1)*facto[i-1]);
    }
    
    auto it = num.begin();
    for(int i=n-1; i>0; i--) {
        int line = (k-1)/facto[i-1];
        answer.push_back(num[line]);
        num.erase(it + line);
        
        k = (!(k%facto[i-1])) ? facto[i-1] : k%facto[i-1];
    } answer.push_back(num[0]);
    
    return answer;
}