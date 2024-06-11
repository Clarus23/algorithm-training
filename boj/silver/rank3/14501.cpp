#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<pair<int, int>> calender(n);
    for(int i=0; i<n; i++) cin >> calender[i].first >> calender[i].second;

    vector<int> payment(n+1, 0);
    for(int i=0; i<n; i++) {
        if(calender[i].first+i > n) continue;

        if(i) payment[i] = max(payment[i], payment[i-1]);
        payment[calender[i].first+i] = max(payment[calender[i].first+i], payment[i]+calender[i].second);
    }
    cout << *max_element(payment.begin(), payment.end());

    return 0;
}