#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<vector<int>> lcs(s1.size()+1, vector<int>(s2.size()+1, 0));
    for(int i=1; i<=s1.size(); i++) {
        for(int j=1; j<=s2.size(); j++) {
            if(s1[i-1] == s2[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = (lcs[i-1][j] > lcs[i][j-1]) ? lcs[i-1][j] : lcs[i][j-1];
        }
    } printf("%d", lcs[s1.size()][s2.size()]);

    return 0;
}