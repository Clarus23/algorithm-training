#include <iostream>
using namespace std;

int main(void) {
    string str;
    int id;
    cin >> str >> id;

    cout << str[id-1];

    return 0;
}