#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;

    int ltag = 1;
    int rtag = 1; // == 0 表示指向后继  == 1 表示指向右孩子

    Node(int d, Node* l, Node* r) {
        data = d;
        lchild = l;
        rchild = r;
    }
};

void mean_order(Node* tree, Node* pre) {
    if (tree == NULL) {
        return ;
    }
    mean_order(tree -> lchild, pre);
    if (tree -> lchild == NULL) {
        tree -> lchild = pre;
        tree -> ltag = 0;
    }

    //前驱的右孩子应该存当前的节点 如果前驱右孩子为空的时候
    if (pre != NULL && pre -> rchild == NULL) {
        pre -> rchild = tree;
        tree -> rtag = 0;
    }

    cout<<tree -> data<<endl;
    pre = tree;

    mean_order(tree -> rchild, pre);
}


int main() {

    Node* Tree = new Node(1, new Node(2, new Node(4, NULL, new Node(7, NULL, NULL)), NULL), 
    new Node(3, new Node(5, NULL, NULL), new Node(6, NULL, NULL)));

    mean_order(Tree, NULL);

    cout<<Tree -> rchild -> lchild -> lchild -> data<<endl;

    return 0;
}