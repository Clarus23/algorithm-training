#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    vector<int> alphabet(26, -1);

    string str;
    cin >> str;

    for(int i=0; i<str.size(); i++) {
        if(alphabet[str[i]-'a'] != -1) continue;
        alphabet[str[i]-'a'] = i;
    }
    for(int i : alphabet) cout << i << ' ';

    return 0;
}