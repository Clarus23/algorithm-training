#include <vector>
#include <queue>

using namespace std;

pair<int, int>& operator+=(pair<int, int>& l, const pair<int, int>& r) {
    l.first += r.first;
    l.second += r.second;
    return l;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    const pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    queue<pair<int, int>> q;
    for(int row=0; row<m; row++) for(int col=0; col<n; col++) {
        if(!picture[row][col]) continue;
        number_of_area++;
        
        const int color = picture[row][col];
        picture[row][col] = 0;
        q.push({row, col}); int count=1;
        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            
            for(pair<int, int> next : dirs) {
                next += cur;
                if(next.first<0 || next.first>=m || next.second<0 || next.second>=n) continue;
                if(picture[next.first][next.second] != color) continue;
                
                picture[next.first][next.second] = 0;
                q.push(next); count++;
            }
        }
        max_size_of_one_area = (count > max_size_of_one_area) ? count : max_size_of_one_area;
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}