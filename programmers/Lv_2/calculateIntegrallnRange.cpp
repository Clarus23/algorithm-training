#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<double> cumlativeArea(1, 0);    //해당 x까지의 누적넓이(정적분)
    while(k!=1) {
        int prevK = k;
        k = (k%2) ? (k*3+1) : (k/2);
        
        cumlativeArea.push_back(cumlativeArea.back() + (double)(prevK+k)/2);
    }
    
    for(vector<int> range : ranges) {
        int start = range[0];
        int end = (range[1] > 0) ? range[1] : range[1] + cumlativeArea.size()-1;
        
        if(start > end) answer.push_back(-1);
        else answer.push_back(cumlativeArea[end] - cumlativeArea[start]);
    }
    
    return answer;
}