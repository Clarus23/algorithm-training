#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string cloth, type;
        map<string, int> clothes;
        while(n--) {
            cin >> cloth >> type;
            clothes[type]++;
        }

        int day = 1;
        for(auto& clothe : clothes) day *= (clothe.second+1); //안 입는다는 선택지를 위해 +1
        cout << day-1 << '\n'; // 모든걸 입지 않은 경우의수 1개를 뺌.
    }
    return 0;
}