#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<int>> recordMap; //차량번호별(key)로 입차, 출차한 시간대(value)를 매핑
    
    for(string record : records) {
        stringstream ss(record);
        string timeStr, carNum;
        ss >> timeStr >> carNum;
        int time = stoi(timeStr.substr(0, timeStr.find(':')))*60 + stoi(timeStr.substr(timeStr.find(':')+1));
        
        recordMap[carNum].push_back(time);
    }
    
    const int lastTime = 1439; // 23*60+59
    for(auto record : recordMap) { // 맵을 사용했기에 알아서 차량번호의 오름차순으로 불러와짐.
        int totalFee = fees[1];
        vector<int> times = record.second;
        if(times.size()%2) times.push_back(lastTime); // 시간의 개수가 홀수다 => 마지막 입차후 출차를 하지 않았다.
        
        int totalTime = 0;
        for(int i=0; i<times.size(); i+=2) totalTime += (times[i+1] - times[i]);
        
        if(totalTime > fees[0]) {
            totalTime -= fees[0];
            totalFee += ((totalTime%fees[2]) ? ((totalTime/fees[2] +1)*fees[3]) : (totalTime/fees[2])*fees[3]); // 올림 처리를 위한 삼항연산자.
        }
        
        answer.push_back(totalFee);
    }
    
    return answer;
}