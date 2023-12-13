#include <string>
#include <vector>
#include <set>

using namespace std;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void permutation(set<int>& s, string numbers, int n, int r, int depth) {
    if(depth == r) {
        string temp = "";
        for(int i=0; i<r; i++) temp += numbers[i];
        s.insert(stoi(temp));
        
        return;
    }
    
    for(int i=depth; i<numbers.size(); i++) {
        swap(numbers[i], numbers[depth]);
        permutation(s, numbers, n, r, depth+1);
        swap(numbers[i], numbers[depth]);
    }
}

bool isPrime(int n) {
    if(n==0 || n==1) return false;
    for(int i=2; i*i<=n; i++) 
        if(!(n%i)) return false;
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> s;
    
    for(int r=1; r<=numbers.size(); r++)
        permutation(s, numbers, numbers.size(), r, 0);
    
    for(auto it=s.begin(); it!=s.end(); it++)
        if(isPrime(*it)) answer++;
    
    return answer;
}