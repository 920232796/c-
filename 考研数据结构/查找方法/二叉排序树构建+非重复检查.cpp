#include<iostream>

using namespace std;

/*  8个数字
8 
64
45
88
36
47
78
99
33

 */

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

int n;
int a[1000];

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

int search_digit(Tree* tree, int key) {
    if (tree == NULL) {
       
        return -1 ;
    }

    if (key < tree -> data) {
        search_digit(tree -> lchild, key);
    } else if (key > tree -> data) {
        search_digit(tree -> rchild, key);
    } else {
        return 1;
    }
}

void create_order_tree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree -> lchild = NULL;
    tree -> rchild = NULL;

    cin>>n;
    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }

    cout<<endl;

    if (n == 0) {
        return ;
    }

    tree -> data = a[0]; //先把根节点赋值

    for (int j = 1; j < n; j ++) {
        ///每次插入新的节点前检查一下 是否有重复节点
        if (search_digit(tree, a[j]) == 1) {
            cout<<"tree构建失败，含有重复节点"<<endl;
            return ;
        }
        insert_node(tree, a[j]);
    }

    //
    cout<<"tree构建成功, 顺序为: "<<endl;
    mean_display(tree);


}


int main() {

    create_order_tree();

    return 0;
}