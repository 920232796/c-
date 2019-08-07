#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;

    Node(int d, Node* l, Node* r) {
        data = d;
        lchild = l;
        rchild = r;
    }
};

void pre_order(Node* tree) {
    if (tree == NULL) {
        return ;
    }
    cout<<tree -> data<<endl;
    pre_order(tree -> lchild);
    pre_order(tree -> rchild);
}


int main() {

    Node* Tree = new Node(1, new Node(2, new Node(4, NULL, new Node(7, NULL, NULL)), NULL), 
    new Node(3, new Node(5, NULL, NULL), new Node(6, NULL, NULL)));

    pre_order(Tree);

    return 0;
}