#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n) {
        data = d;
        next = n;
    }
};

int main() {

    Node* node = new Node(5, new Node(4, new Node(8, new Node(1, new Node(4, new Node(4, NULL))))));
    Node* q = node -> next -> next; //这时候 q 里面存储的是地址，谁的地址？？ 就是 节点 8 的地址！！所以现在如果释放掉q 
    // cout<<q -> data<<endl;
    q -> next = NULL;
    // free(q);

    while (node != NULL) {
        cout<<node -> data<<endl;
        node = node -> next;
    }

    //从输出可以看到，q存的节点8 的地址， 改变的q 也就改变了节点8， 而节点8 是位于 node 上面的，因此也就改变了node !! 这就是存地址的作用

    // 若 q里面存的不是 地址  就是值传递，就算去修改q node 不会跟着改变

    return 0;
}