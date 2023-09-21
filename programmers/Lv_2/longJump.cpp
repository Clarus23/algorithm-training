#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long combination(int n, int r, long long (*memo)[2001]) {
    if(memo[n][r] == 0) {
        memo[n][r] = (combination(n-1, r-1, memo)%1234567) + (combination(n-1, r, memo)%1234567);
    }
    
    return memo[n][r];
}

long long solution(int n) {
    long long answer = 0;
    long long memo[2001][2001] = {0,};  //memo[n][r] == nCr
    
    for(int i=0; i<2001; i++) {
        memo[i][0] = 1;
        memo[i][i] = 1;
    }
    
    for(int r=0; r<n/2+1; r++) answer = (answer + (combination(n-r, r, memo)%1234567))%1234567;
    
    return answer;
}