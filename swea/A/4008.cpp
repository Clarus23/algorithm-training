#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
* dfs - backtracking
* 연산자의 개수를 알고 있으니 dfs를 수행하며 그 자리에 넣을 수 있는 모든 연산자를 넣어본다.
* depth == n 이 되면 => 모든 숫자를 연산하였으면, 값을 계산하고 max, min을 업데이트한다.
* dfs의 매개변수 : 연산자 배열, 숫자 배열, min/max값, n값, 중간 연산결과, depth
*
*
* 시간 복잡도 O(N^2)
* 메모리 5,992 kb
* 실행시간 17 ms
*/

void dfs(vector<int>& ops, const vector<int>& nums, pair<int, int>& minMax
    , const int& n, int cur, int depth) {
    if (depth == n) {
        minMax.first = (cur < minMax.first) ? cur : minMax.first;
        minMax.second = (cur > minMax.second) ? cur : minMax.second;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (!ops[i]) continue;

        --ops[i];
        if (i == 0) dfs(ops, nums, minMax, n, cur + nums[depth], depth + 1);
        else if (i == 1) dfs(ops, nums, minMax, n, cur - nums[depth], depth + 1);
        else if (i == 2) dfs(ops, nums, minMax, n, cur * nums[depth], depth + 1);
        else dfs(ops, nums, minMax, n, cur / nums[depth], depth + 1);
        ++ops[i];
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n; cin >> n;

        vector<int> ops(4);
        vector<int> nums(n);
        for (int& op : ops) cin >> op;
        for (int& num : nums) cin >> num;

        pair<int, int> minMax = { INT_MAX, INT_MIN };
        dfs(ops, nums, minMax, n, nums[0], 1);

        cout << "#" << tc << " " << minMax.second - minMax.first << "\n";
    }

    return 0;
}