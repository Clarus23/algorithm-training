#include <iostream>
using namespace std;

int main(void) {
    int ascendingArr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int descendingArr[8] = {8, 7, 6, 5, 4, 3, 2, 1};

    bool isAscending = true;
    bool isDescending = true;

    int n;
    for(int i=0; i<8; i++) {
        cin >> n;
        if(n != ascendingArr[i]) isAscending = false;
        if(n != descendingArr[i]) isDescending = false;
    }

    if(isAscending) cout << "ascending";
    else if(isDescending) cout << "descending";
    else cout << "mixed";

    return 0;
}