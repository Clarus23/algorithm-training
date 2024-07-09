#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    map<string, bool> names;
    string name;
    for(int i=0; i<n; i++) {
        cin >> name;
        names.insert({name, true});
    }

    int cnt=-1;
    string* answer = new string[n];
    for(int i=0; i<m; i++) {
        cin >> name;
        if(names[name]) answer[++cnt] = name;
    } sort(answer, answer+(++cnt));

    cout << cnt << '\n';
    for(int i=0; i<cnt; i++) cout << answer[i] << '\n';

    delete []answer;
    return 0;
}