#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int* q = new int[n];
    int front = -1, rear = -1;

    string op; int item;
    for(int i=0; i<n; i++) {
        cin >> op;

        if(op == "push") {
            cin >> item;
            q[++rear] = item;
        }
        else if(op == "pop") cout << ((front == rear) ? -1 : q[++front]) << '\n';
        else if(op == "size") cout << (rear - front) << '\n';
        else if(op == "empty") cout << (front == rear) << '\n';
        else if(op == "front") cout << ((front == rear) ? -1 : q[front+1]) << '\n';
        else if(op == "back") cout << ((front == rear) ? -1 : q[rear]) << '\n';
    }

    delete[] q;

    return 0;
}