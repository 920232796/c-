#include<iostream>
//两次遍历 得到两个链表的长度
using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char d, Node* n) {
        data = d;
        next = n;
    }
};

void solve(Node* node_1, Node* node_2) {

    Node* temp = node_1;
    Node* temp_2 = node_2;
    Node* p ; //存最后需要的那个节点

    int length_1 = 0;
    int length_2 = 0;

    while (temp != NULL) {
        length_1 += 1;
        temp = temp -> next;
    }

    while (temp_2 != NULL) {
        length_2 += 1;
        temp_2 = temp_2 -> next;
    }

    if (length_1 > length_2) {

        for (int i = 0; i < length_1 - length_2; i ++) {
            node_1 = node_1 -> next;
        }

    } else {
        for (int i = 0; i < length_2 - length_1; i ++) {
            node_2 = node_2 -> next;
        }
    }

    while (node_1 != NULL && node_2 != NULL) {
        
        //找公共结点
        if (node_1 == node_2) {
            cout<<node_1 -> data<<endl;
            return ;
        }
        node_1 = node_1 -> next;
        node_2 = node_2 -> next;
    }


}   

int main() {

    Node* same = new Node('i', new Node('n', new Node('g', NULL)));

    Node* node_1 = new Node('l', new Node('o', new Node('a', new Node('d', same))));

    Node* node_2 = new Node('b', new Node('e', same));


    Node* temp = node_1;
    while (temp != NULL)  {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }

    cout<<endl;

    Node* temp_2 = node_2;
    while (temp_2 != NULL)  {
        cout<<temp_2 -> data<<" ";
        temp_2 = temp_2 -> next;
    }

    cout<<endl;

    solve(node_1, node_2);

    return 0;
}