#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

pair<long long, long long>& operator+=(pair<long long, long long>& left, const long long right) {
    left.first += right;
    left.second += right;
    return left;
}

int solution(int n, long long l, long long r) {
    const int adds[4] = {0, 1, 2, 1}; // <- 누적 덧셈 (1번: +0, 2번: +1, 3번: +3, 4번: +4)
    vector<bool> bits(r-(--l), false);
    
    vector<pair<long long, long long>> stack(1, {0, pow(5, n)});
    while(!stack.empty()) {
        pair<long long, long long> section = stack.back(); stack.pop_back();
        long long sep = (section.second-section.first)/5;
        /**
        * section -> [section.first, section.second)
        * ---------------------------------------------
        * subSection 1 : [section.first + sep*0, section.first + sep*1)
        * subSection 2 : [section.first + sep*1, section.first + sep*2)
        * subSection 3 : [section.first + sep*3, section.first + sep*4)
        * subSection 4 : [section.first + sep*4, section.first + sep*5)
        */
        
        if(sep == 1) {
            for(int add : adds) {
                section.first += add;
                if(section.first < l || section.first >= r) continue;
                bits[section.first-l] = true;
            } continue;
        }
        
        pair<long long, long long> subSection = {section.first, section.first+sep};
        for(int add : adds) {
            subSection += (sep*add);
            if(subSection.second < l || subSection.first >= r) continue;
            stack.push_back(subSection);
        }
    }
    
    return count(bits.begin(), bits.end(), true);
}