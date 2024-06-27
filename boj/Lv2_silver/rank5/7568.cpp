#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n; cin >> n;
    int* rank = new int[n];
    pair<int, int>* build = new pair<int, int>[n];
    for(int i=0; i<n; i++) {
        rank[i] = 1;
        cin >> build[i].first >> build[i].second;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(build[i].first < build[j].first && build[i].second < build[j].second) rank[i]++;
    for(int i=0; i<n; i++) cout << rank[i] << ' ';

    delete []rank;
    delete []build;
    return 0;
}