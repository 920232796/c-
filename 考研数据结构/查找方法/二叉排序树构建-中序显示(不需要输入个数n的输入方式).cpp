#include<iostream>

using namespace std;


struct Tree {
    int data;
    Tree* lchild;
    Tree* rchild;
    Tree(int d, Tree* l, Tree* r) {
        data = d;
        lchild = l;
        rchild = r;
    }
};

void mean_display(Tree* tree) {
    if (tree == NULL) {
        return ;

    }

    mean_display(tree -> lchild);
    cout<<tree -> data<<endl;
    mean_display(tree -> rchild);
}

void insert_node(Tree* tree, int c) {

    if (c < tree -> data) {
        if (tree -> lchild == NULL) {
            // 那么直接给左孩子就ok了
            Tree* child = new Tree(c, NULL, NULL);
            tree -> lchild = child;
        } else {
            // 否则递归 看看能不能把c插入到 左孩子作为根节点的子树中
            insert_node(tree -> lchild, c);
        }
    } else {
        if (tree -> rchild == NULL) {
            Tree* child = new Tree(c, NULL, NULL);
            tree -> rchild = child;
        } else {
            insert_node(tree -> rchild, c);
        }
    }
}

void create_order_tree() {

    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree -> lchild = NULL;
    tree -> rchild = NULL;

    int c;
    cin>>c;

    if (c != 65535) {
       tree -> data = c;
    }

    while (c != 65535) {
        cin>>c;
        if (c != 65535 && tree != NULL) {
            insert_node(tree, c);
        }
    }

    mean_display(tree);

   
}


int main() {

    create_order_tree();

    return 0;
}