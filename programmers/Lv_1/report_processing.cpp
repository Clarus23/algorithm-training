#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<string>> reportList;
    map<string, int> reportNum;
    set<string> reportSet;
    
    vector<string> temp;
    for(string id : id_list) {
        reportList.insert({id, temp});
        reportNum.insert({id, 0});
    }
    for(string repo : report) reportSet.insert(repo);
    
    for(auto iter = reportSet.begin(); iter != reportSet.end(); iter++) {
        string reporter = (*iter).substr(0, (*iter).find(" "));
        string reported = (*iter).substr((*iter).find(" ")+1);
        
        reportList[reporter].push_back(reported);
        reportNum[reported]++;
    }
    
    for(string reporterId : id_list) {
        answer.push_back(0);
        for(string reportedId : reportList[reporterId])
            if(reportNum[reportedId] >= k) answer.back()++;
    }
    
    
    return answer;
}