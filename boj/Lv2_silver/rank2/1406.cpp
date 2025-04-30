#include <iostream>
using namespace std;

class Node {
    friend class NodeList;
private:
    char data;
    Node* prev;
    Node* next;

public:
    Node() {
        prev = nullptr;
        next = nullptr;
    }
    Node(char data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
    ~Node() {}
};

class NodeList {
private:
    Node root = Node();
    Node* cursor;

public:
    NodeList() {
        cursor = &root;
    }
    NodeList(const string& str) {
        cursor = &root;

        for(char c : str) {
            Node* node = new Node(c);

            node->prev = cursor;
            cursor->next = node;
            cursor = node;
        }
    }
    ~NodeList() {}

    bool cursorIsHead() { return (cursor->prev == nullptr); }
    bool cursorIsTail() { return (cursor->next == nullptr); }

    void cursorLeft() {
        if(cursorIsHead()) return;

        cursor = cursor->prev;
    }
    void cursorRight() {
        if(cursorIsTail()) return;

        cursor = cursor->next;
    }
    void deleteNode() {
        if(cursorIsHead()) return;

        cursor->prev->next = cursor->next;
        if(!cursorIsTail())
            cursor->next->prev = cursor->prev;
        cursor = cursor->prev;
    }
    void addNode(char data) {
        Node* node = new Node(data);

        node->prev = cursor;
        node->next = cursor->next;

        if(!cursorIsTail())
            cursor->next->prev = node;
        cursor->next = node;

        cursor = node;
    }

    void printList() {
        Node* it = &root;

        while(it->next != nullptr) {
            cout << it->next->data;
            it = it->next;
        }
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str; cin >> str;
    NodeList nodeList = NodeList(str);

    int ic; cin >> ic;
    cin.ignore();
    for(int i=0; i<ic; i++) {
        string op; getline(cin, op);

        if(op[0] == 'L') nodeList.cursorLeft();
        else if(op[0] == 'D') nodeList.cursorRight();
        else if(op[0] == 'B') nodeList.deleteNode();
        else nodeList.addNode(op[2]);
    }

    nodeList.printList();

    return 0;
}