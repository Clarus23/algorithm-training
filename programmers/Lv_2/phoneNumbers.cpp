#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool comp(string a, string b) {
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), comp);
    set<string> phoneNum;
    
    const int minSize = phone_book[0].size();
    for(string number : phone_book) {
        for(int i=number.size()-1; i>=minSize; i--) 
            if(phoneNum.find(number.substr(0, i)) != phoneNum.end()) return false;
        
        phoneNum.insert(number);
    }
    
    return true;
}