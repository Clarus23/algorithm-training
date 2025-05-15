#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

class Node {
public:
    int bffNum;
    int voidNum;
    pair<int, int> coord;

    Node() {
        bffNum = 0;
        voidNum = 0;
    }
};

void operator+=(pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int n; cin >> n;
    vector<vector<pair<int, int>>> classRoom(n, vector<pair<int, int>>(n, {-1, 0}));

    vector<int> order(n*n);
    vector<set<int>> bffs(n*n);
    for(int& student : order) {
        cin >> student;
        --student;

        for(int i=0; i<4; i++) {
            int bff; cin >> bff;
            bffs[student].insert(bff-1);
        }
    }

    for(const int& student : order) {
        vector<Node> seatInfo(n*n);
        for(int row=0; row<n; row++) for(int col=0; col<n; col++) {
            if(classRoom[row][col].first != -1) {
                seatInfo[row * n + col].coord = {n, n};
                continue;
            }
            seatInfo[row * n + col].coord = {row, col};

            for(pair<int, int> fringe : dirs) {
                fringe += {row, col};

                if(fringe.first < 0 || fringe.first >= n || fringe.second < 0 || fringe.second >= n) continue;

                if(classRoom[fringe.first][fringe.second].first == -1) seatInfo[row * n + col].voidNum++;
                else if(bffs[student].find(classRoom[fringe.first][fringe.second].first) != bffs[student].end()) seatInfo[row * n + col].bffNum++;
            }
        }

        Node seat = *min_element(seatInfo.begin(), seatInfo.end(), [](const auto& prev, const auto& next) {
            return (prev.bffNum > next.bffNum)
                || (prev.bffNum == next.bffNum && prev.voidNum > next.voidNum)
                || (prev.bffNum == next.bffNum && prev.voidNum == next.voidNum && prev.coord.first < next.coord.first)
                || (prev.bffNum == next.bffNum && prev.voidNum == next.voidNum && prev.coord.first == next.coord.first && prev.coord.second < next.coord.second);
        });

        classRoom[seat.coord.first][seat.coord.second] = {student, seat.bffNum};
        for(pair<int, int> fringe : dirs) {
            fringe += seat.coord;

            if(fringe.first < 0 || fringe.first >= n || fringe.second < 0 || fringe.second >= n) continue;
            if(classRoom[fringe.first][fringe.second].first == -1) continue;

            if(bffs[classRoom[fringe.first][fringe.second].first].find(student) != bffs[classRoom[fringe.first][fringe.second].first].end())
                classRoom[fringe.first][fringe.second].second++;
        }
    }

    int satisfaction = 0;
    for(int row=0; row<n; row++) {
        for(int col=0; col<n; col++) {
            if(classRoom[row][col].second == 0) continue;
            satisfaction += (int)pow(10, classRoom[row][col].second-1);
        }
    }

    cout << satisfaction;

    return 0;
}