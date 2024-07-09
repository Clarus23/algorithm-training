#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    string* numToName = new string[n];
    map<string, int> nameToNum;
    for(int i=0; i<n; i++) {
        char temp[20];
        scanf("%s", temp);

        numToName[i] = temp;
        nameToNum.insert({numToName[i], i+1});
    }

    string poketmon;
    for(int i=0; i<m; i++) {
        char temp[21];
        scanf("%s", temp);
        poketmon = temp;

        if(poketmon[0] >= '0' && poketmon[0] <= '9') cout << numToName[stoi(poketmon)-1] << '\n';
        else printf("%d\n", nameToNum[poketmon]);
    }

    delete []numToName;
    return 0;
}