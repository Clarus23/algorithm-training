#include <string>
#include <vector>
#include <cmath>

using namespace std;

string decToBin(int dec, int& countOne) {
    string bin = "";
    for(int i=19; i>=0; i--) {
        int bit = (dec >> i) & 1;
        if(bin=="" && bit==0) continue;
        
        if(bit == 1) countOne++; //1 개수 세기
        bin += (bit+'0');
    }
    return bin;
}
int binToDec(string bin) {
    int dec = 0;
    int digit = bin.size()-1;
    for(char bit : bin) dec += ((bit-'0') * (int)pow(2,digit--));
    return dec;
}
void binAdd(string& bin, int& lostOne, int pos) {
    bin = "0" + bin;
    pos++;
    
    while(true) {
        if(bin[pos] == '0') {
            bin[pos] = '1'; break;
        } else {
            bin[pos] = '0'; pos--;
            lostOne++;
        }
    } lostOne--;
    
    if(bin[0] == '0') bin = bin.substr(1);
}

int solution(int n) {
    int answer = 0;
    int countOne = 0;
    
    string binN = decToBin(n, countOne);
    int lastOne = 0;
    for(int i=binN.size()-1; i>=0; i--) {
        if(binN[i] == '1') {
            lastOne = i; break;
        }
    }
    int lostOne = 0;
    binAdd(binN, lostOne, lastOne);
    
    for(int i=0; i<lostOne; i++) binN[binN.size()-1-i] = '1';
    
    answer = binToDec(binN);
    
    return answer;
}