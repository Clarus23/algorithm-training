#include <iostream>
using namespace std;

int main(void) {
    string week[7] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
    int month[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int m, d;
    cin >> d >> m;
    cout << week[month[m-1]+d];

    return 0;
}