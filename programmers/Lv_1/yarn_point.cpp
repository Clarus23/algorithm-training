#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photos) {
    vector<int> answer;
    map<string, int> yearnMap;
    
    for(int i=0; i<name.size(); i++) yearnMap.insert({name[i], yearning[i]});
    
    for(vector<string> photo : photos) {
        int yearn = 0;
        for(string person : photo) {
            auto find = yearnMap.find(person);
            if(find != yearnMap.end()) yearn += find->second;
        }
        answer.push_back(yearn);
    }
    
    return answer;
}