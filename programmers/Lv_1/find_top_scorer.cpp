#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3] = {0,};
    int answer2[4] = {1,3,4,5};
    int answer3[5] = {3,1,2,4,5};
    
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == i%5+1) score[0]++;
        
        if((i%2) && (answers[i] == answer2[(i/2)%4])) score[1]++;
        else if(!(i%2) && (answers[i] == 2)) score[1]++;
        
        if(answers[i] == answer3[(i%10)/2]) score[2]++;
    }
    
    int max = (score[0]>score[1]) ? score[0] : score[1];
    max = (max>score[2]) ? max : score[2];
    
    for(int i=0; i<3; i++) if(score[i] == max) answer.push_back(i+1);
    
    return answer;
}