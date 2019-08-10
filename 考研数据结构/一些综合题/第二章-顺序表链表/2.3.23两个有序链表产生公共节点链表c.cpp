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

void solve(Node* A, Node* B) {
    Node* node_c = new Node(-1, NULL);

    Node* c_head = node_c;
    Node* a_head = new Node(-1, A);
    Node* b_head = new Node(-1, B);

    while (a_head -> next != NULL && b_head -> next != NULL) {
        if (a_head -> next -> data == b_head -> next -> data) {
            Node* temp = new Node(a_head -> next -> data, NULL); //这样就不会破坏原来的A B 节点 新建一个新的节点
            c_head -> next = temp;
            c_head = c_head -> next;

            a_head = a_head -> next;
            b_head = b_head -> next;

        } else if (a_head -> next -> data < b_head -> next -> data) {
            a_head = a_head -> next;
        } else {
            b_head = b_head -> next;
        }
    }

    while (node_c -> next != NULL ) {
        cout<<node_c -> next -> data<<" ";
        node_c = node_c -> next;
    }

}

int main() {

    Node* node_A = new Node(1, new Node(4, new Node(5, new Node(8, new Node(4, NULL)))));

    Node* node_B = new Node(2, new Node(3, new Node(4, new Node(8, new Node(9, new Node(11, NULL))))));

    Node* temp_1 = node_A;
    while (temp_1 != NULL)  {
        cout<<temp_1 -> data<<" ";
        temp_1 = temp_1 -> next;
    }
    cout<<endl;

    Node* temp_2 = node_B;
    while (temp_2 != NULL)  {
        cout<<temp_2 -> data<<" ";
        temp_2 = temp_2 -> next;
    }
    cout<<endl;

    solve(node_A, node_B);

    return 0;
}