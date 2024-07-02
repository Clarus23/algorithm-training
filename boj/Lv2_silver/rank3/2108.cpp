#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
    int frequency[8001] = {0, };

    int n; scanf("%d", &n);
    vector<int> numbers(n);
    int avg = 0;
    for(int& number : numbers) {
        scanf("%d", &number);

        avg += number;
        frequency[number+4000]++;
    } sort(numbers.begin(), numbers.end());

    avg = (int)round((double)avg/n);
    int id1 = max_element(frequency, frequency+8001) - frequency;
    int id2 = max_element(frequency+id1+1, frequency+8001) - frequency;
    int mode = (frequency[id1]==frequency[id2]) ? id2-4000 : id1-4000;
    printf("%d\n%d\n%d\n%d", avg, numbers[n/2], mode, numbers[n-1]-numbers[0]);

    return 0;
}