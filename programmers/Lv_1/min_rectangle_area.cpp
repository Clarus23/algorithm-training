#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    //무조건 긴쪽은 가로, 짧은쪽은 세로로 생각함.
    int maxWidth = max(sizes[0][0], sizes[0][1]);
    int maxHeight = min(sizes[0][0], sizes[0][1]);
    for(vector<int> size : sizes) {
        int width = max(size[0], size[1]);
        int height = min(size[0], size[1]);
        
        maxWidth = (width > maxWidth) ? width : maxWidth;
        maxHeight = (height > maxHeight) ? height : maxHeight;
    }
    answer = maxWidth * maxHeight;
    
    return answer;
}