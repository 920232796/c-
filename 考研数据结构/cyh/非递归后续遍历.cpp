#include<iostream>
#include<stack>

using namespace std;


struct Tree {

    Tree* lchild;
    Tree* rchild;
    int data;

    Tree(int d, Tree* l, Tree* r) {
        lchild = l;
        rchild = r;
        data = d;
    }
};

stack<Tree*> s1;
stack<Tree*> s2;

void solve(Tree* tree) {
    Tree* t = tree;

    while (t || !s1.empty()) {
        //只有遍历完所有结点，循环才会结束！

        while (t) {
            s1.push(t);
            s2.push(t);
            t = t -> rchild;
        }
        //说明已经到头了，现在要回溯一下
        t = s1.top();
        s1.pop();
        t = t -> lchild;
    }

    while (!s2.empty()) {
        Tree* t = s2.top();
        s2.pop();
        cout<<t -> data<<" ";
    }

}

int main() {

    Tree* tree = new Tree(1, new Tree(2, new Tree(3, NULL, NULL), new Tree(4, NULL, NULL)), new Tree(5, NULL, NULL));

    solve(tree);

    return 0;
}