#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Crain {
  public:
    int item;
    int pos;
    
    Crain() {}
    void set(int item, int pos) {
        this->item = item; this->pos = pos;
    }
};

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    const int size = board.size();
    vector<Crain> highestItem(size);
    vector<int> stack;
    
    
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(board[j][i] != 0) {
                highestItem[i].set(board[j][i], j);
                break;
            }
        }
    }
    
    for(int move : moves) {
        int thisItem = highestItem[move-1].item;
        int thisPos = highestItem[move-1].pos;
        
        if(thisPos >= size) continue;
        
        if(stack.empty()) stack.push_back(thisItem);
        else {
            int recentItem = stack.back();
            
            if(thisItem == recentItem) {
                stack.pop_back();
                answer += 2;
            } else stack.push_back(thisItem);
        }
        
        if(thisPos+1 >= size) highestItem[move-1].set(0, thisPos+1);
        else highestItem[move-1].set(board[thisPos+1][move-1], thisPos+1);
    }
    
    return answer;
}