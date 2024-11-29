#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* leftChild;
    Node* rightChild;

    Node(int value) {
        this->value = value;

        leftChild = nullptr;
        rightChild = nullptr;
    }

    bool isLeaf() { return (leftChild == nullptr && rightChild == nullptr); }
    bool isExistLeft() { return (leftChild != nullptr); }
    bool isExistRight() { return (rightChild != nullptr); }
};

void recursivePrintF(Node* node) {
    if(node->isLeaf()) {
        printf("%d\n", node->value);
        return;
    }

    if(node->isExistLeft()) recursivePrintF(node->leftChild);
    if(node->isExistRight()) recursivePrintF(node->rightChild);
    printf("%d\n", node->value);
}

int main() {
    int temp; cin >> temp;
    Node root(temp);

    while(cin >> temp) {
        Node* ptr = &root;
        while(true) {
            if(temp < ptr->value) {
                if(ptr->isExistLeft()) ptr = ptr->leftChild;
                else {
                    ptr->leftChild = new Node(temp);
                    break;
                }
            } else {
                if(ptr->isExistRight()) ptr = ptr->rightChild;
                else {
                    ptr->rightChild = new Node(temp);
                    break;
                }
            }
        }
    }

    recursivePrintF(&root);

    return 0;
}