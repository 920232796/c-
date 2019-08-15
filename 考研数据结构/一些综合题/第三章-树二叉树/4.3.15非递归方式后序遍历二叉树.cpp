#include<iostream>
#include<stack>

//注意  后序和中右左刚好相反，先序正好是中左右，都是中开头，因此它俩差不多 代码基本一样， 把数值push到另一个stack里面！
using namespace std;

//栈的方式其实就是用栈 完成了回溯！！ 来遍历

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

stack<Tree*> s1;
stack<Tree*> s2;

void solve(Tree* tree) {

    Tree* T = tree;

    while (T || !s1.empty()) {
       
       while (T) {
            s2.push(T);
            s1.push(T);
            T = T -> rchild;

       }
       T = s1.top();
       s1.pop();
       T = T -> lchild;

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