#include<iostream>
//先得到两个节点段的长度，然后相减为n 然后长的节点段先遍历n个节点 然后同时遍历 直到找到公共节点
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n) {
        data = d;
        next = n;
    }
};

void solve(Node* node_1, Node* node_2) {
    int len_node_1 = 0;
    int len_node_2 = 0;
    Node* temp_1 = node_1;
    Node* temp_2 = node_2;
    while (temp_1 != NULL) {
        len_node_1 ++;
        temp_1 = temp_1 -> next;
    }

    while (temp_2 != NULL) {
        len_node_2 ++;
        temp_2 = temp_2 -> next;
    }
    if (len_node_1 > len_node_2) {
        for (int i = 0; i < len_node_1 - len_node_2; i ++) {
            node_1 = node_1 -> next;
        }
    }
    if (len_node_1 < len_node_2) {
        for (int i = 0; i < len_node_2 - len_node_1; i ++) {
            node_2 = node_2 -> next;
        }
    }

    while (true) {
        if (node_1 == node_2) {
            cout<<"result : "<<node_1 -> data<<endl;
            return ;
        }
        node_1 = node_1 -> next;
        node_2 = node_2 -> next;
    }

}


int main() {

    //公共节点段
    Node* node = new Node(9, new Node(8, new Node(7, NULL)));

    //两个节点段 找它俩的公共节点
    Node* node1 = new Node(5, new Node(4, new Node(8, new Node(1, new Node(4, new Node(4, node))))));
    Node* node2 = new Node(3, new Node(1, node));

    Node* temp = node1;
    while (temp != NULL)  {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;

    Node* temp2 = node2;
    while (temp2 != NULL)  {
        cout<<temp2 -> data<<" ";
        temp2 = temp2 -> next;
    }
    cout<<endl;

    solve(node1, node2);

    return 0;
}