#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int xpos[10] = {3,0,0,0,1,1,1,2,2,2};
    int ypos[10] = {1,0,1,2,0,1,2,0,1,2};
    
    int left[2] = {3,0};
    int right[2] = {3,2};
    int goal[2] = {0,0};
    
    for(int number : numbers) {
        switch(number) {
            case 1: case 4: case 7:
                answer += "L";
                left[0] = xpos[number]; left[1] = ypos[number];
                break;
            case 3: case 6: case 9:
                answer += "R";
                right[0] = xpos[number]; right[1] = ypos[number];
                break;
            default:
                goal[0] = xpos[number]; goal[1] = ypos[number];
                int leftDist = abs(left[0]-goal[0]) + abs(left[1]-goal[1]);
                int rightDist = abs(right[0]-goal[0]) + abs(right[1]-goal[1]);
                
                if(leftDist < rightDist || (leftDist == rightDist && hand == "left")) {
                    answer += "L";
                    left[0] = goal[0]; left[1] = goal[1];
                } else {
                    answer += "R";
                    right[0] = goal[0]; right[1] = goal[1];
                }
                break;
        }
    }
    
    return answer;
}