#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Item {
public:
    char id;
    pair<int, int> coord;
    int timer;

    Item(char id, pair<int, int> coord, int timer) {
        this->id = id;
        this->coord = coord;
        this->timer = timer;
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

    int r, c;
    cin >> r >> c;

    queue<Item> q;
    pair<int, int> jihoon;

    vector<string> maze(r);
    for(int i=0; i<r; i++) {
        cin >> maze[i];
        for(int j=0; j<c; j++) {
            if(maze[i][j] == 'J') {
                jihoon = {i, j};
                maze[i][j] = '#';
            } else if(maze[i][j] == 'F') {
                q.push(Item('f', {i, j}, 1));
                maze[i][j] = '#';
            }
        }
    }
    q.push(Item('j', jihoon, 1));

    bool isEnd = false;
    while(!q.empty() && !isEnd) {
        char who = q.front().id;
        pair<int, int> cur = q.front().coord;
        int timer = q.front().timer;
        q.pop();

        for(pair<int, int> next : dirs) {
            next += cur;

            if(next.first < 0 || next.first >= r || next.second < 0 || next.second >= c) {
                if(who == 'f') continue;

                cout << timer;
                isEnd = true;
                break;
            }
            if(maze[next.first][next.second] == '#') continue;


            maze[next.first][next.second] = '#';
            q.push(Item(who, next, timer+1));
        }
    }

    if(!isEnd) cout << "IMPOSSIBLE";

    return 0;
}