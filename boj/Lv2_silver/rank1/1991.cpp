#include <iostream>
#include <vector>
using namespace std;

string pre(const vector<pair<char, char>>& tree, char cur) {
    string answer(1, cur);
    char left = tree[cur-'A'].first;
    char right = tree[cur-'A'].second;

    if(left == '.'  && right == '.') return answer;

    if(left != '.') answer += pre(tree, left);
    if(right != '.') answer += pre(tree, right);
    return answer;
}
string in(const vector<pair<char, char>>& tree, char cur) {
    string answer(1, cur);
    char left = tree[cur-'A'].first;
    char right = tree[cur-'A'].second;

    if(left == '.'  && right == '.') return answer;

    if(left != '.') answer = in(tree, left) + answer;
    if(right != '.') answer += in(tree, right);
    return answer;
}
string post(const vector<pair<char, char>>& tree, char cur) {
    string answer(1, cur);
    char left = tree[cur-'A'].first;
    char right = tree[cur-'A'].second;

    if(left == '.'  && right == '.') return answer;

    if(right != '.') answer = post(tree, right) + answer;
    if(left != '.') answer = post(tree, left) + answer;
    return answer;
}

int main(void) {
    int n; cin >> n;
    vector<pair<char, char>> tree(n);
    for(int i=0; i<n; i++) {
        char root; cin >> root;
        cin >> tree[root-'A'].first >> tree[root-'A'].second;
    }

    cout << pre(tree, 'A') << '\n' << in(tree, 'A') << '\n' << post(tree, 'A');

    return 0;
}