#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string quadCompression(vector<vector<int>>& arr, int size, int x, int y) {
    bool flag[4] = {true, true, true, true};
    int init[4] = {arr[x][y], arr[x][y+size/2], arr[x+size/2][y], arr[x+size/2][y+size/2]};
    
    for(int i=0; i<size/2; i++) {
        for(int j=0; j<size/2; j++) {
            if(arr[x+i][y+j] != init[0]) flag[0] = false;
            if(arr[x+i][y+size/2+j] != init[1]) flag[1] = false;
            if(arr[x+size/2+i][y+j] != init[2]) flag[2] = false;
            if(arr[x+size/2+i][y+size/2+j] != init[3]) flag[3] = false;
            
            if(!flag[0] && !flag[1] && !flag[2] && !flag[3]) break;
        }
        
        if(!flag[0] && !flag[1] && !flag[2] && !flag[3]) break;
    }
    
    string answer[4];
    for(int i=0; i<4; i++) answer[i] = to_string(init[i]);
    if(!flag[0]) answer[0] = "(" + quadCompression(arr, size/2, x, y) + ")";
    if(!flag[1]) answer[1] = "(" + quadCompression(arr, size/2, x, y+size/2) + ")";
    if(!flag[2]) answer[2] = "(" + quadCompression(arr, size/2, x+size/2, y) + ")";
    if(!flag[3]) answer[3] = "(" + quadCompression(arr, size/2, x+size/2, y+size/2) + ")";
    
    return answer[0] + answer[1] + answer[2] + answer[3];
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    string s = quadCompression(arr, arr.size(), 0, 0);
    if(s.find('0') == string::npos) return {0,1};
    if(s.find('1') == string::npos) return {1,0};
    
    sort(s.begin(), s.end());
    int count0 = s.find('1') - s.find('0');
    int count1 = s.size() - s.find('1');
    
    answer.push_back(count0);
    answer.push_back(count1);
    
    return answer;
}