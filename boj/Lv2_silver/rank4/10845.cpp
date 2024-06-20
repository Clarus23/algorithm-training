#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    int *queue = new int[n+1];
    int front = 0, rear = 0;
    string cmd; int element;
    for(int i=0; i<n; i++) {
        cin >> cmd;
        if(cmd == "push") {
            scanf("%d", &element);
            rear = (rear+1)%(n+1);
            queue[rear] = element;
        } else if(cmd == "pop") {
            if(front == rear) printf("-1\n");
            else {
                front = (front+1)%(n+1);
                printf("%d\n", queue[front]);
            }
        } else if(cmd == "front") {
            if(front == rear) printf("-1\n");
            else printf("%d\n", queue[front+1]);
        } else if(cmd == "back") {
            if(front == rear) printf("-1\n");
            else printf("%d\n", queue[rear]);
        }
        else if(cmd == "empty") printf("%d\n", (front == rear));
        else if(cmd == "size") printf("%d\n", (n+1+rear-front)%(n+1));
    }
    delete []queue;

    return 0;
}