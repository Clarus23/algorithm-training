#include <cstdio>

int main() {
	char score[2];
	scanf("%c%c", score, score+1);
	
	double ans = 4;
	if(score[0] == 'F') {
		printf("0.0");
		return 0;
	}
	ans -= (score[0] - 'A');
	
	if(score[1] == '+') ans += 0.3;
	else if(score[1] == '-') ans -= 0.3;
	printf("%.1lf", ans);
	return 0;
}
	
