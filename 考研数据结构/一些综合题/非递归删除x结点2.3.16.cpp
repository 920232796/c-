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

void del_node(Node* node, int x) {

    Node* pre = new Node(-1, node);
    Node* q;//用来保住需要删除的节点 然后释放掉

    while (node != NULL) {
        if (node -> data != x) {
            node = node -> next;
            pre = pre -> next;
            continue;
        }
        // ==x 
        q = node;
        pre -> next = node -> next;
        free(q);
        node = pre -> next;
    }
}


int main() {

    Node* node = new Node(5, new Node(4, new Node(8, new Node(1, new Node(4, new Node(4, NULL))))));

    Node* temp = node;
    while (temp != NULL)  {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;

    del_node(node, 4);

    while (node != NULL)  {
        cout<<node -> data<<" ";
        node = node -> next;
    }
    return 0;
}