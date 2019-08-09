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

void solve(Node* node) {
    if (node == NULL || node -> next == NULL) {
        return ;
    }
    Node* head = new Node(-1, node);

    Node* p = head -> next;
    //不断的把p的 next 插入到head 之前 头插法
    while (p -> next != NULL) {
        Node* temp = p -> next;
        p -> next = p -> next -> next;

        temp -> next = head -> next;
        head -> next = temp;
    }

    while (head != NULL) {
        cout<<head -> next -> data<<" ";
        head = head -> next;
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

    solve(node);

    return 0;
}