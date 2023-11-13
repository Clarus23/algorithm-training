#include <string>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

bool comp(string file1, string file2) {
    regex reg("[0-9]{1,5}");
    smatch match;
    
    regex_search(file1, match, reg);
    string head1 = match.prefix();
    int number1 = stoi(match.str());
    
    regex_search(file2, match, reg);
    string head2 = match.prefix();
    int number2 = stoi(match.str());
    
    transform(head1.begin(), head1.end(), head1.begin(), ::tolower);
    transform(head2.begin(), head2.end(), head2.begin(), ::tolower);
    
    if(head1 < head2) return true;
    else if(head1 == head2 && number1 < number2) return true;
    else return false;
}

vector<string> solution(vector<string> files) {
    // sort함수를 사용하면, quick sort를 이용하기 때문에 불안정한 정렬(같은 원소의 순서를 보장해주지 않음)이 됨.
    // 반면, stable_sort는 merge sort를 이용하기 때문에 안정한 정렬(같은 원소의 순서를 보장해줌)을 보장함.
    // 그렇기 때문에, sort가 아닌 stable_sort를 사용했음.
    stable_sort(files.begin(), files.end(), comp);
    return files;
}