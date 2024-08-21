#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string p, arr;
        int n;
        cin >> p >> n >> arr;
        arr = arr.substr(1, arr.size()-2);


        int start=0, end=0;
        stringstream ss(arr);
        string temp;
        vector<int> v(n, 0);
        while(getline(ss, temp, ',')) v[end++] = stoi(temp);

        bool reverse = false, error = false;
        for(char function : p) {
            if(function == 'R') {
                reverse = !reverse;
                continue;
            }

            if(start == end) {
                error = true;
                break;
            }

            if(reverse) end--;
            else start++;
        }

        if(error) cout << "error\n";
        else {
            cout << '[';
            if(start != end) {
                if(reverse) {
                    for(int i=end-1; i > start; i--) cout << v[i] << ',';
                    cout << v[start];
                } else {
                    for(int i=start; i < end-1; i++) cout << v[i] << ',';
                    cout << v[end-1];
                }
            } cout << "]\n";
        }
    }

    return 0;
}