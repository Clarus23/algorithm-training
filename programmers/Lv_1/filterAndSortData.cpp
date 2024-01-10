#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    map<string, int> column = {{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}};
    
    auto end = remove_if(data.begin(), data.end(), [col = column[ext], valExt = val_ext](const auto& a) {
        return a[col] >= valExt;
    });
    data.erase(end, data.end());
    
    sort(data.begin(), data.end(), [col = column[sort_by]](const auto& a, const auto& b) {
        return a[col] < b[col];
    });
    
    return data;
}