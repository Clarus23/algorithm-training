#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, bool> calculate(string& exp, vector<bool>& isFirst) {
    int numDq[10]; char opDq[9];
    int numFront = -1, numRear = -1, opFront = -1, opRear = -1;

    numDq[++numRear] = exp[0] - '0';
    for(int i=0; i<isFirst.size(); i++) {
        if(isFirst[i]) {
            if(i < isFirst.size()-1 && isFirst[i+1])
                return {0, false};

            int num = numDq[numRear--];

            if(exp[i*2 + 1] == '+') num += (exp[i*2 + 2] - '0');
            else if(exp[i*2 + 1] == '-') num -= (exp[i*2 + 2] - '0');
            else num *= (exp[i*2 + 2] - '0');

            numDq[++numRear] = num;
            continue;
        }

        opDq[++opRear] = exp[i*2 + 1];
        numDq[++numRear] = exp[i*2 + 2] - '0';
    }

    int result = numDq[++numFront];
    while(opFront != opRear) {
        char op = opDq[++opFront];
        int num = numDq[++numFront];

        if(op == '+') result += num;
        else if(op == '-') result -= num;
        else result *= num;
    }

    return {result, true};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string exp; cin >> exp;

    vector<bool> isFirst(n/2, false);
    int max = calculate(exp, isFirst).first;

    for(int i=1; i<n/2; i++) {
        isFirst[i-1] = true;

        do {
            pair<int, bool> candidate = calculate(exp, isFirst);
            if(!candidate.second) continue;

            max = (candidate.first > max) ? candidate.first : max;
        } while(prev_permutation(isFirst.begin(), isFirst.end()));
    }

    cout << max;

    return 0;
}