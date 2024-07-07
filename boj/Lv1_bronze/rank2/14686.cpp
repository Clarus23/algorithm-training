#include <iostream>
using namespace std;

int main(void) {
    int n; cin >> n;

    int swiftsSum=0, semaphoresSum=0;
    int *swiftsPoints = new int[n];
    int *semaphoresPoints = new int[n];
    for(int i=0; i<n; i++) {
        cin >> swiftsPoints[i];
        swiftsSum += swiftsPoints[i];
    }
    for(int i=0; i<n; i++) {
        cin >> semaphoresPoints[i];
        semaphoresSum += semaphoresPoints[i];
    }

    int k=0;
    for(int i=n-1; i>=0; i--) {
        if(swiftsSum == semaphoresSum) {
            k = (i+1);
            break;
        }

        swiftsSum -= swiftsPoints[i];
        semaphoresSum -= semaphoresPoints[i];
    } cout << k;

    delete [] swiftsPoints;
    delete [] semaphoresPoints;
    return 0;
}