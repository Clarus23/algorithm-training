#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux=50, luy=50, rdx=0, rdy=0;
    
    for(int i=0; i<wallpaper.size(); i++) {
        for(int j=0; j<wallpaper[0].size(); j++) {
            if(wallpaper[i][j] == '#') {
                lux = min(lux, i);
                luy = min(luy, j);
                rdx = max(rdx, i+1);
                rdy = max(rdy, j+1);
            }
        }
    }
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);
    return answer;
}