#include<iostream>

using namespace std;

//二叉树 按完全二叉树存，若某节点空 则为 -10000 

int n = 13;

int i = 3;
int j = 9; //找下标为3 的结点跟 下标为 9的结点的公共结点~ 答案应该是下标为1的结点 值也为1! 

void solve(int tree[]) {

    while (i != j) {
        if (i < j) {
            //找j的父亲
            if (j % 2 == 0) {
                j = (j - 2) / 2;
            } else {
                j = (j - 1) / 2;
            }
        } else {
            if (i % 2 == 0) {
                i = (i - 2) / 2;
            } else {
                i = (i - 1) / 2;
            }
        }

    }

    cout<<tree[i]<<endl;
}


int main() {
    int tree[100];

    for (int i = 0; i < n; i ++) {
        tree[i] = i;
    }

    for (int i = 0; i < n; i ++) {
        cout<<tree[i]<<" ";
    }   

    cout<<endl;

    solve(tree);

    return 0;
}