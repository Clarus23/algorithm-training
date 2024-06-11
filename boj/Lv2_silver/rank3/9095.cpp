#include <iostream>
#include <vector>
using namespace std;

int count(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;

    return count(n-1)+count(n-2)+count(n-3);
}

int main(void) {
    int testCase;
    cin >> testCase;
    vector<int> number(testCase);
    for(int i=0; i<testCase; i++) cin >> number[i];

    for(int num : number) cout << count(num) << '\n';

    return 0;
}