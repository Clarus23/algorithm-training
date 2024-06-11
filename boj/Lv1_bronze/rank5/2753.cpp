#include <iostream>
using namespace std;

int main(void) {
    int year;
    cin >> year;

    cout << (bool)((!(year%4) && (year%100)) || !(year%400));

    return 0;
}