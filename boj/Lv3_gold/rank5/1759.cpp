#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int l, c;
    cin >> l >> c;

    vector<char> candidate(c);
    for(int i=0; i<c; i++) cin >> candidate[i];
    sort(candidate.begin(), candidate.end());

    vector<bool> flag(c, false);
    for(int i=0; i<l; i++) flag[i] = true;

    vector<char> key(l);
    do {
        int top=0;
        int vowelCnt=0;
        for(int i=0; i<c; i++) {
            if(flag[i]) {
                if(candidate[i]=='a' || candidate[i]=='e' || candidate[i]=='i' || candidate[i]=='o' || candidate[i]=='u') vowelCnt++;
                key[top++] = candidate[i];
            }
        }

        if(vowelCnt && (l-vowelCnt)>=2) {
            for(char c : key) cout << c;
            cout << '\n';
        }
    } while(prev_permutation(flag.begin(), flag.end()));

    return 0;
}