#include <iostream>
using namespace std;

#define M 1234567891

int main(void) {
    string str;
    int length;
    cin >> length >> str;

    long long hash = 0, r = 1;
    for(int i=0; i<length; i++) {
        hash = (hash + ((str[i]-96)*r))%M;
        r = (r*31)%M;
    }

    cout << hash;

    return 0;
}