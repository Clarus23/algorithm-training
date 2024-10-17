#include <iostream>
#include <vector>
using namespace std;

void func(vector<string>& base, int n) {
    if(n == 3) return;

    vector<string> temp(base);

    int size = base.size();
    string s = ""; for(int i=0; i<size; i++) s += " ";

    for(int i=0; i<size; i++) base[i] = s + temp[i] + s;
    for(int i=0; i<size; i++) {
        base.push_back(temp[i] + " " + temp[i]);
        s.pop_back();
    }

    func(base, n/2);
}

int main() {
    int n; cin >> n;

    vector<string> base = {"  *  ", " * * ", "*****"};
    func(base, n);
    for(string s : base) cout << s << '\n';

    return 0;
}