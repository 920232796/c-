#include<iostream>
//两次遍历就行 第一次记录链表长度噢
using namespace std;

int k;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n) {
        data = d;
        next = n;
    }
};

void solve(Node* node) {

    Node* temp = node;

    Node* temp_2 = node;

    int length = 0;
    while (temp != NULL) {
        length += 1;
        temp = temp -> next;
    }

    cout<<"length为: "<<length<<endl;

    for (int i = 0; i < length - k; i ++) {
        temp_2 = temp_2 -> next;
    }
    cout<<temp_2 -> data<<endl;
}   

int main() {

    Node* node = new Node(5, new Node(4, new Node(8, new Node(1, new Node(4, new Node(4, NULL))))));

    Node* temp = node;
    cout<<"please 输入 k 也就是想要输出倒数第k个结点"<<endl;
    cin>>k;
    while (temp != NULL)  {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }

    cout<<endl;

    solve(node);


    return 0;
}