#include <algorithm>

using namespace std;

int gcdFunc(int a, int b) {
    while(b) {
        int mod = a%b;
        a = b;
        b = mod;
    } return a;
}

long long solution(int w,int h) {
    if(w > h) swap(w, h);
    long long answer = (long long)w*h;
    
    int gcd = gcdFunc(h, w);
    int w1 = w/gcd; int h1 = h/gcd;
    int n = w/w1;
    
    int deleted = w1*h1;
    for(int x=1; x<w1; x++) {
        double y = h1*(1 - (double)x/w1);
        deleted -= (int)y*2;
    }
    
    answer -= deleted*n;
    
    return answer;
}