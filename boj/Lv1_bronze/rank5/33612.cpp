#include <iostream>
using namespace std;

int main() {
	int year = 2024;
	int month = 1;
	
	int n; cin >> n;
	
	month += (7*n);
	
	year += (month/12);
	month %= 12;
	
	if(month == 0) {
		--year;
		month = 12;
	}
	
	cout << year << " " << month;
	
	return 0;
}