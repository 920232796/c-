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
    if (node -> next == NULL) {
        return ;
    }
    if (node -> next -> data == x) {
        // Node* temp = node -> next -> next;
        // free(node -> next);
        node -> next = node -> next -> next;
        // free(temp);
        del_node(node, x);
        return ;
    }

    del_node(node -> next, x);
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

    del_node(node, 4);

    while (node != NULL)  {
        cout<<node -> data<<" ";
        node = node -> next;
    }
    return 0;
}