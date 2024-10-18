#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; scanf("%d", &n);

    vector<int> prevMin(3, 0);
    vector<int> prevMax(3, 0);
    vector<int> curMin(3, 0);
    vector<int> curMax(3, 0);

    for(int i=0; i<n; i++) {
        int col0, col1, col2;
        scanf("%d %d %d", &col0, &col1, &col2);

        curMin[0] = *min_element(prevMin.begin(), prevMin.begin()+2) + col0;
        curMin[1] = *min_element(prevMin.begin(), prevMin.end()) + col1;
        curMin[2] = *min_element(prevMin.begin()+1, prevMin.end()) + col2;

        curMax[0] = *max_element(prevMax.begin(), prevMax.begin()+2) + col0;
        curMax[1] = *max_element(prevMax.begin(), prevMax.end()) + col1;
        curMax[2] = *max_element(prevMax.begin()+1, prevMax.end()) + col2;

        prevMin = curMin;
        prevMax = curMax;
    }

    printf("%d %d", *max_element(prevMax.begin(), prevMax.end()), *min_element(prevMin.begin(), prevMin.end()));

    return 0;
}