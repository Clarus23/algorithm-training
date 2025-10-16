#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int n;
ll minSum;

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
	a.first += b.first;
	a.second += b.second;
}

void calculate(vector<pair<int, int>>& arr, pair<int, int> vecSum, int depth, int start) {
	if(depth == n/2) {
		ll sum = (ll)vecSum.first*vecSum.first + (ll)vecSum.second*vecSum.second;
		minSum = (sum < minSum) ? sum : minSum;
		return;
	}
	
	if(n - start < n/2 - depth) return;
	
	for(int i=start; i<arr.size(); ++i)
		calculate(arr, {vecSum.first - 2*arr[i].first, vecSum.second - 2*arr[i].second}, depth+1, i+1);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int t; cin >> t;
	while(t--) {
		cin >> n;
		
		pair<int, int> vecSum = {0, 0};
		vector<pair<int, int>> arr(n);
		for(int i=0; i<n; ++i) {
			int first, second;
			cin >> first >> second;
			
			arr[i] = {first, second};
			vecSum += arr[i];
		}
		
		minSum = 9e18;
		calculate(arr, vecSum, 0, 0);
		
		cout << fixed;
		cout.precision(12);
		cout << sqrt((double)minSum) << "\n";
	}
	
	return 0;
}
