#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    const int size = friends.size();
    
    map<string, int> name;
    for(int i=0; i<size; i++) name.insert({friends[i], i});
    
    vector<vector<int>> giftsTable(size, vector<int>(size, 0));
    vector<int> giftsIndices(size, 0);
    for(string gift : gifts) {
        string sender = gift.substr(0, gift.find(' '));
        string recipient = gift.substr(gift.find(' ')+1);
        
        giftsTable[name[sender]][name[recipient]]++;
        giftsIndices[name[sender]]++;
        giftsIndices[name[recipient]]--;
    }
    
    vector<int> reciveGift(size, 0);
    for(int i=0; i<size; i++) {
        string sender = friends[i];
        for(int j=i+1; j<size; j++) {
            string recipient = friends[j];
            
            if(giftsTable[name[sender]][name[recipient]] > giftsTable[name[recipient]][name[sender]])
                reciveGift[name[sender]]++;
            else if(giftsTable[name[sender]][name[recipient]] < giftsTable[name[recipient]][name[sender]])
                reciveGift[name[recipient]]++;
            else {
                if(giftsIndices[name[sender]] > giftsIndices[name[recipient]])
                    reciveGift[name[sender]]++;
                else if(giftsIndices[name[sender]] < giftsIndices[name[recipient]])
                    reciveGift[name[recipient]]++;
            }
        }
    }
    
    return *max_element(reciveGift.begin(), reciveGift.end());
}