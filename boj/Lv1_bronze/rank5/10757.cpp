#include <iostream>
using namespace std;

string sum(string n1, string n2) {
    string result = "";
    int size1 = n1.size(), size2 = n2.size();
    if(size1 > size2) for(int i=0; i<size1-size2; i++) n2 = "0"+n2;
    else for(int i=0; i<size2-size1; i++) n1 = "0"+n1;

    int op = 0, temp;
    for(int i=n1.size()-1; i>=0; i--) {
        temp = op + n1[i] + n2[i] - 2*'0';
        op = temp/10;
        result = to_string(temp%10) + result;
    } if(op) result = to_string(op) + result;

    return result;
}

int main(void) {
    string n1, n2;
    cin >> n1 >> n2;
    cout << sum(n1, n2);
    return 0;
}