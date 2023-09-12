#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    string winStr = "";

    for(int num : win_nums) {
        if(num < 10) winStr += ("0" + to_string(num) + ",");
        else winStr += (to_string(num) + ",");
    }

    int zero=0; int rank=7;
    for(int lotto : lottos) {
        string num = (lotto < 10) ? ("0"+to_string(lotto)) : to_string(lotto);

        if(lotto == 0) zero++;
        else if(winStr.find(num) != string::npos) rank--;
    }

    answer.push_back((rank-zero == 7) ? 6 : rank-zero);
    answer.push_back((rank == 7) ? 6 : rank);
    return answer;
}
