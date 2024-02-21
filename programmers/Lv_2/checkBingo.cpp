#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    vector<string> lines(8, ""); // 0,1,2 행 / 3,4,5 열 / 6,7 대각
    int cntO=0, cntX=0;
    int lineO=0, lineX=0;
    
    for(int i=0; i<3; i++) {
        lines[6] += board[i][i];
        lines[7] += board[i][2-i];
        for(int j=0; j<3; j++) {
            lines[i] += board[i][j];
            lines[3+i] += board[j][i];
            if(board[i][j] == 'O') cntO++;
            if(board[i][j] == 'X') cntX++;
        }
    }
    if(cntO < cntX || cntO > cntX+1) return 0;
    
    vector<int> temp;
    for(int i=0; i<8; i++) {
        if(lines[i] == "OOO") lineO++;
        else if(lines[i] == "XXX") lineX++;
        temp.push_back(i);
    }
    if(lineO && cntO==cntX) return 0; //선공이 빙고를 채웠는데 선공과 후공의 칸 개수가 같을 수는 없음.
    if(lineX && cntO>cntX) return 0;  //후공이 빙고를 채웠는데 선공이 후공보다 칸 개수가 많을 수는 없음.
    if(lineO>2 || lineX>2 || (lineO && lineX)) return 0; // 3줄 빙고 혹은 선공과 후공이 둘다 빙고인 경우는 없음.
    if(temp[0]%3!=2 && temp[0]%3==temp[1]%3) return 0; // 가로줄끼리 혹은 세로줄끼리의 2줄 빙고인 경우는 없음.
    
    return 1;
}