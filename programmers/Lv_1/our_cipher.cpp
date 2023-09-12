#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    for(int i=0; i<skip.size(); i++) alphabet[skip[i]-'a']=' ';
    sort(alphabet.begin(), alphabet.end());
    alphabet = alphabet.substr(skip.size());
    
    int size = alphabet.size();
    for(char c : s) {
        int sIndex = alphabet.find(c);
        
        if(sIndex + index < size) answer += alphabet[sIndex+index];
        else answer += alphabet[(sIndex+index)%size];
    }
    
    return answer;
}