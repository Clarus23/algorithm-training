#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int tc=0; tc<10; tc++) {
        int dump; cin >> dump;
        int boxes[100];
        for(int& box : boxes) cin >> box;

        int diff;
        for(int i=0; i<dump; i++) {
            diff = (*max_element(boxes, boxes+100))-- - (*min_element(boxes, boxes+100))++;

            if(diff <= 1) break;
        }
        diff = *max_element(boxes, boxes+100) - *min_element(boxes, boxes+100);

        cout << "#" << tc+1 << ' ' << diff << '\n';
    }

    return 0;
}