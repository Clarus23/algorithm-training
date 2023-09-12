#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int i=0, j=0;
    for(string word : goal) {
        if(cards1[i] == word) i++;
        else if(cards2[j] == word) j++;
        else {
            answer = "No";
            break;
        }
    }
    
    return answer;
}