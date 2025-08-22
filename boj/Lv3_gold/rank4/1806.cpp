#include <iostream>
#include <vector>
using namespace std;

/*
 * # 풀이 아이디어: 구간합, 투포인터
 * ## 입력받을때, 구간합을 구한 다음, 투포인터를 이용하여 값 계산.
 * 
 * # 메모리: 2,804 kb
 * # 실행시간: 8 ms
 * # 체감 난이도: 하
 */

typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;

    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    int minLength = 2e9;
    int start = 0; int end = 1;
    while (true) {
        if (start >= end || end > n) break;

        ll subSum = sum[end] - sum[start];
        if (subSum < s) {
            ++end; continue;
        }

        int length = end - start++;
        minLength = (length < minLength) ? length : minLength;
    }

    cout << ((minLength == 2e9) ? 0 : minLength);

    return 0;
}