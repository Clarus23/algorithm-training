#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i=0; i<n; i++) cin >> numbers[i];
    sort(numbers.begin(), numbers.end());
    for(int number : numbers) cout << number << '\n';

    return 0;
}