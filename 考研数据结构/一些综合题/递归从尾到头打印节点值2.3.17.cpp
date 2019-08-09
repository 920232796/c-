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

void print_node(Node* node) {
    if (node -> next != NULL) {
        print_node(node -> next);
       
    }
    cout<<node -> data<<" ";
}

int main() {

    Node* node = new Node(5, new Node(4, new Node(8, new Node(1, new Node(4, new Node(4, NULL))))));

    print_node(node);

    // while (node != NULL)  {
    //     cout<<node -> data<<" ";
    //     node = node -> next;
    // }
    return 0;
}