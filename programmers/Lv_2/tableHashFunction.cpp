#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    sort(data.begin(), data.end(), [t = col-1](const vector<int>& a, const vector<int>& b) {
        if(a[t] < b[t]) return true;
        if(a[t] == b[t] && a[0] > b[0]) return true;
        return false;
    });
    
    int answer = 0;
    for(int i=row_begin; i<=row_end; i++) {
        int sum = 0;
        for(int d : data[i-1]) sum += (d%i);
        answer ^= sum;
    }
    
    return answer;
}