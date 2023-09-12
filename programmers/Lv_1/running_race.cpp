#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> ranks;
    
    for(int i=0; i<players.size(); i++) {
        ranks.insert({players[i], i});
    }
    
    for(string name: callings) {
        int rank = ranks[name];
        swap(players[rank-1], players[rank]);
        
        ranks[name]--;
        ranks[players[rank]]++;
    }
    
    answer.swap(players);
    
    return answer;
}