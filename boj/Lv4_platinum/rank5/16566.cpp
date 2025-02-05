#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//union_find 사용

int parentIndex[4000001];

int find(int num) {
    if(num == parentIndex[num]) return num;
    else return find(parentIndex[num]);
}

void merge(int num1, int num2) {
    num1 = find(num1);
    num2 = find(num2);

    if(num1 != num2) parentIndex[num1] = num2;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    vector<int> hand(m);
    parentIndex[m] = m;
    while(m--) {
        scanf("%d", &hand[m]);
        parentIndex[m] = m;
    } sort(hand.begin(), hand.end());

    while(k--) {
        int card; scanf("%d", &card);

        int index = upper_bound(hand.begin(), hand.end(), card) - hand.begin();
        index = find(index);
        printf("%d\n", hand[index]);
        merge(index, index+1);
    }

    return 0;
}