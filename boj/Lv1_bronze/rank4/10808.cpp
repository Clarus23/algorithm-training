#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int alphabet[26] = {0, };
    string word; cin >> word;

    for(char c : word)
        alphabet[c - 'a']++;

    for(int count : alphabet) cout << count << ' ';

    return 0;
}