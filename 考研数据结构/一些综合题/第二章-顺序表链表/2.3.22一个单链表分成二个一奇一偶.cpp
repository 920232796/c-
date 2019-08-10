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
    
    Node* B_head = new Node(-1, NULL);
    Node* A_head = new Node(-1, node);

    Node* q = A_head;
    Node* p = B_head;

    while (q -> next != NULL) {
        if ((q -> next -> data) % 2 == 0) {
            //偶数
            Node* temp = q -> next;
            q -> next = q -> next -> next;
            p -> next = temp;
            p = p -> next;
            p -> next = NULL;
            continue;
        }
        if (q -> next -> data % 2 != 0) {
            //奇数
            // cout<< q -> next -> data<<endl;
            q = q -> next;
            continue;
        }
    }

    while (A_head -> next != NULL) {
        cout<<A_head -> next -> data<<" ";
        A_head = A_head -> next;
    }
    cout<<endl;
    while (B_head -> next != NULL) {
        cout<<B_head -> next -> data<<" ";
        B_head = B_head -> next;
    }   
}

int main() {

    Node* node = new Node(5, new Node(4, new Node(8, new Node(1, new Node(4, new Node(3, NULL))))));

    Node* temp = node;
    while (temp != NULL)  {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;

    solve(node);

    return 0;
}