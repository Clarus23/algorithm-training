#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(void) {
    string str;
    getline(cin, str);

    stringstream ss(str);
    string word;
    vector<string> words;
    while(getline(ss, word, ' ')) if(word != "") words.push_back(word);

    cout << words.size();

    return 0;
}