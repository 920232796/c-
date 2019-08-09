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

void del_node(Node* node) {

    Node* pre = new Node(-1, node); //node 前驱节点
    Node* q; // 这个q很关键 是用来保存那个需要删除的最小节点 循环结束之后 最小节点就确定了 这时候就可以删掉了
    int min_data = 100000;

    while (node != NULL) {
        if (node -> data < min_data) {
            q = pre;
            min_data = node -> data;
            continue;
        }
        pre = pre -> next;
        node = node -> next;
    }

    
    q -> next = q -> next -> next;
    return ;
   

   
}


int main() {

    Node* node = new Node(5, new Node(4, new Node(8, new Node(1, new Node(4, new Node(4, NULL))))));

    Node* temp = node;
    while (temp != NULL)  {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;

    del_node(node);

    while (node != NULL)  {
        cout<<node -> data<<" ";
        node = node -> next;
    }
    return 0;
}