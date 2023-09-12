#include <string>
#include <vector>
#include <map>

using namespace std;

class Date {
  public:
    int year;
    int month;
    int day;
    
    Date() {}
    Date(int year, int month, int day) {
        if(month > 12) {
            this->month = (month%12) ? month%12 : 12;
            this->year = (month%12) ? (year+month/12) : (year-1+month/12);
        } else {
            this->month = month;
            this->year = year;
        }
        this->day = day;
    }
    
    bool isDestruction(Date& deadline) {
        if(year > deadline.year) return true;
        if(year == deadline.year && month > deadline.month) return true;
        if(year == deadline.year && month == deadline.month && day >= deadline.day) return true;
        
        return false;
    }
};

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> myTerms;
    Date myToday(stoi(today.substr(0,4)), stoi(today.substr(5,2)), stoi(today.substr(8,2)));
    
    for(string term : terms) myTerms.insert({term[0], stoi(term.substr(2))});
    
    int it=1;
    for(string privacy : privacies) {
        int term = myTerms.at(privacy[11]);
        Date myPrivacy(stoi(privacy.substr(0,4)), stoi(privacy.substr(5,2)), stoi(privacy.substr(8,2)));
        Date deadline(myPrivacy.year, myPrivacy.month+term, myPrivacy.day);
        
        if(myToday.isDestruction(deadline)) answer.push_back(it);
        it++;
    }
    
    return answer;
}