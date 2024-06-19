#include <iostream>
using namespace std;

int main(void) {
    int answer;
    string str;
    for(int i=3; i>0; i--) {
        cin >> str;
        if(str[0] >= '0' && str[0] <= '9') answer = stoi(str)+i;
    }

    if(!(answer%15)) cout << "FizzBuzz";
    else if(!(answer%3)) cout << "Fizz";
    else if(!(answer%5)) cout << "Buzz";
    else cout << answer;

    return 0;
}