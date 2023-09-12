#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> temp;
    
    for(int i=0; i<n; i++) {
        temp.push_back(arr1[i] | arr2[i]);
        answer.push_back("");
        for(int j=n-1; j>=0; j--) {
            int bin = (temp[i] >> j) & 1;
            answer[i] += (bin) ? "#" : " ";
        }
    }

    return answer;
}