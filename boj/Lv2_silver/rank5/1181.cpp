#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string *words = new string[n];
    for(int i=0; i<n; i++) cin >> words[i];
    sort(words, words+n, [](string first, string second) {
        if(first.size() < second.size()) return true;
        if(first.size() == second.size() && first < second) return true;
        return false;
    });

    cout << words[0] << '\n';
    for(int i=1; i<n; i++) {
        if(words[i] == words[i-1]) continue;
        cout << words[i] << '\n';
    }
    delete []words;
    return 0;
}