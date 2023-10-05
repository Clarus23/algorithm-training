#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <set>

using namespace std;

bool comp(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> temp;

    s =  s.substr(2, s.size()-4);
    s = regex_replace(s, regex("},\\{"), "\\") + "\\";

    while(s != "") {
        string subS = s.substr(0, s.find("\\")) +",";
        s = s.substr(s.find("\\")+1);

        temp.push_back(vector<int>());
        while(subS != "") {
            temp.back().push_back(stoi(subS.substr(0, subS.find(","))));
            subS = subS.substr(subS.find(",")+1);
        }
    }

    sort(temp.begin(), temp.end(), comp);

    set<int> isExist;
    for(vector<int> v : temp) {
        for(int i : v) {
            if(isExist.find(i) == isExist.end()) {
                answer.push_back(i);
                isExist.insert(i);
                break;
            }
        }
    }

    return answer;
}