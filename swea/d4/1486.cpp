#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase; cin >> testCase;
    for(int t=1; t<=testCase; t++) {
        int n, b;
        cin >> n >> b;
        
        int* clerks = new int[n];
        for(int i=0; i<n; i++) cin >> clerks[i];

        int best = 2e9;
        int max = (1 << n);
        for(int bit=1; bit<max; bit++) {
            int sum = 0;
            for(int i=0; i<n; i++) {
                if(bit & (1 << i)) sum += clerks[i];

                if(sum >= b) break;
            }

            if(sum >= b) best = (best < sum) ? best : sum;
        }

        cout << '#' << t << ' ' << best - b << '\n';

        delete[] clerks;
    }

    return 0;
}