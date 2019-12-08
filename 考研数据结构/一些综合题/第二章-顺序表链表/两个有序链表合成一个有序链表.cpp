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

void solve(Node* node1, Node* node2) {
    //两个指针
    Node* res = new Node(-1, NULL);
    Node* head = res;
    while (node1 != NULL && node2 != NULL) {
        if (node1 -> data > node2 -> data) {
            head -> next = node2;
            head = head -> next;
            node2 = node2 -> next;
        } else {
            head -> next = node1;
            head = head -> next;
            node1 = node1 -> next;
        }
    }
    if (node1 == NULL) {
        while (node2 != NULL) {
            head -> next = node2;
            head = head -> next;
            node2 = node2 -> next;
        }
    } else if (node2 == NULL) {
        while (node1 != NULL) {
            head -> next = node1;
            head = head -> next;
            node1 = node1 -> next;
        }
    }

    while (res -> next != NULL) {
        cout<<res -> next -> data<<" ";
        res = res -> next;
    }
    cout<<endl;
}


int main() {

    Node* node1 = new Node(1, new Node(3, new Node(5, new Node(7, NULL))));
    Node* node2 = new Node(2, new Node(4, new Node(6, NULL)));

    solve(node1, node2);
    return 0;
}