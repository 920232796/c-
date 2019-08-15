#include<iostream>
#include<stack>

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

stack<Tree*> s;

void solve(Tree* tree) {

    Tree* T = tree;

    while (T || !s.empty()) {
        while (T) {
            cout<<T ->data<<" ";

            s.push(T);
            T = T -> lchild;

        }
        T = s.top();
        s.pop();
        T = T -> rchild;
    }
}


int main() {

    Tree* tree = new Tree(1, new Tree(2, new Tree(3, NULL, NULL), new Tree(4, NULL, NULL)), new Tree(5, NULL, NULL));

    solve(tree);


    return 0;
}