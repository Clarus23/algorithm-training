#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int index=0;
    while(k > 0) {
        if(index == number.size()-1 && number[index] < number[index-1]) {
            number.erase(index--, 1);
            k--;
            continue;
        }
        
        if(number[index] < number[index+1]) {
            number.erase(index, 1);
            if(index) index--;
            k--;
            continue;
        }
        
        index++;
    }
    
    return number;
}