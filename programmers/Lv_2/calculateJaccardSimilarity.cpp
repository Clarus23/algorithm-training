#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1;
    vector<string> v2;
    
    //str1, str2 의 모든 영문자를 소문자로 변환.
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    int size1 = str1.size(), size2 = str2.size();
    int maxSize = (size1 > size2) ? size1 : size2;
    for(int i=0; i<maxSize-1; i++) {
        if(i<size1-1 && (str1[i]>='a' && str1[i]<='z' && str1[i+1]>='a' && str1[i+1]<='z'))
            v1.push_back(str1.substr(i,2));
        if(i<size2-1 && (str2[i]>='a' && str2[i]<='z' && str2[i+1]>='a' && str2[i+1]<='z'))
            v2.push_back(str2.substr(i,2));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    double jaccardSim = 0;
    if(v1.empty() && v2.empty()) jaccardSim = 1;
    else {
        vector<string> unionSet(v1.size() + v2.size());         //합집합
        vector<string> intersectionSet(v1.size() + v2.size());  //교집합
        vector<string>::iterator iter;
        
        iter = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), unionSet.begin());
        unionSet.erase(iter, unionSet.end());
        
        iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), intersectionSet.begin());
        intersectionSet.erase(iter, intersectionSet.end());
        
        jaccardSim = (double)intersectionSet.size() / unionSet.size();
    }
    
    answer = (int)(jaccardSim * 65536);
    
    return answer;
}