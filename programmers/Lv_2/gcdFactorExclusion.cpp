#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if(!b) return a;
    else return gcd(b, a%b);
}
vector<pair<int, char>> factor(int n, char c) {
    if(n==1) return {};
    
    vector<pair<int, char>> v(1, {n, c});
    for(int i=2; i*i<=n; i++) {
        if(i*i == n) v.push_back({i, c});
        else if(!(n%i)) {
            v.push_back({i, c});
            v.push_back({n/i, c});
        }
    }
    return v;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    if(arrayA.size() == 1) {
        if((arrayA[0]%arrayB[0]) && (arrayB[0]%arrayA[0]))
            return (arrayA[0] > arrayB[0]) ? arrayA[0] : arrayB[0];
        if((arrayB[0]%arrayA[0])) return arrayA[0];
        if((arrayA[0]%arrayB[0])) return arrayB[0];
        return 0;
    }
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    vector<pair<int, char>> candidateV = factor(gcd(arrayA[1], arrayA[0]), 'a');
    vector<pair<int, char>> temp = factor(gcd(arrayB[1], arrayB[0]), 'b');
    candidateV.insert(candidateV.end(), temp.begin(), temp.end());
    sort(candidateV.begin(), candidateV.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });
    
    for(auto candidate : candidateV) {
        int num = candidate.first;
        __gnu_cxx::__normal_iterator<int *, vector<int, allocator<int>>> itA, itB;
        if(candidate.second == 'a') {
            itA = find_if(arrayA.begin(), arrayA.end(), [n=num](const int& a) { return (a%n); });
            itB = find_if(arrayB.begin(), arrayB.end(), [n=num](const int& b) { return !(b%n); });
        } else {
            itA = find_if(arrayA.begin(), arrayA.end(), [n=num](const int& a) { return !(a%n); });
            itB = find_if(arrayB.begin(), arrayB.end(), [n=num](const int& b) { return (b%n); });
        }
        
        if(itA == arrayA.end() && itB == arrayB.end()) return num;
    }
    
    return 0;
}