#include <iostream>
#include <vector>
using namespace std;

int function(vector<int>& shortArr, vector<int>& longArr) {
    int max = 0;

    for(int i=0; i+shortArr.size() <= longArr.size(); i++) {
        int candidate = shortArr[0]*longArr[i];
        for(int j=1; j<shortArr.size(); j++) candidate += shortArr[j]*longArr[i+j];
        max = (max > candidate) ? max : candidate;
    }

    return max;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int testCase; cin >> testCase;
    for(int t=1; t<=testCase; t++) {
        int n, m;
        cin >> n >> m;

        vector<int> arrA(n);
        vector<int> arrB(m);
        for(int& a : arrA) cin >> a;
        for(int& b : arrB) cin >> b;

        int max = (n < m) ? function(arrA, arrB) : function(arrB, arrA);

        cout << '#' << t << ' ' << max << '\n';
    }

    return 0;
}