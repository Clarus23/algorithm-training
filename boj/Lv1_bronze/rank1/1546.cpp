#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> scores(n);
    for(int i=0; i<n; i++) cin >> scores[i];

    int maxScore = *max_element(scores.begin(), scores.end());
    double sum = 0;
    for(int i=0; i<n; i++) sum += (((double)scores[i]/maxScore)*100);

    cout << sum/n;

    return 0;
}