#include <iostream>
using namespace std;

class Time {
private:
    int hh, mm, ss;
public:
    Time(string time) {
        hh = stoi(time.substr(0, 2));
        mm = stoi(time.substr(3, 2));
        ss = stoi(time.substr(6, 2));
    }

    Time& operator++(int) {
        ss++;
        if(ss==60) {
            mm++;
            ss = 0;
        } if(mm==60) {
            hh++;
            mm = 0;
        } if(hh==24) hh=0;
        return *this;
    }
    friend bool operator==(const Time &t1, const Time &t2) {
        return (t1.ss==t2.ss && t1.mm==t2.mm && t1.hh==t2.hh);
    }
    bool isMultiple3() {
        return !((hh*10000+mm*100+ss)%3);
    }
};

int main(void) {
    string time1, time2;
    for(int t=0; t<3; t++) {
        cin >> time1 >> time2;
        Time cur(time1), target(time2);

        int cnt=0;
        while(true) {
            if(cur.isMultiple3()) cnt++;
            if(cur==target) break;
            cur++;
        } cout << cnt << '\n';
    }
}