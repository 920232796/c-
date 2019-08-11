#include<iostream>
#include<map>

using namespace std;

map<int, int> m;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n) {
        data = d;
        next = n;
    }
};

void solve(Node* node) {
    Node* head = new Node(-1, node);
    Node* head_node = head;
    Node* q;

    while (head -> next != NULL && head != NULL) {
        if (m[abs(head -> next -> data)] != 0) {
            //证明出现过 删掉此结点
            q = head -> next;
            head -> next = head -> next -> next;
            free(q);
        } else {
            m[abs(head -> next -> data)] = 1;
            head = head -> next;
        }
        
    }

    while (head_node -> next != NULL) {
        cout<<head_node -> next -> data<<" ";
        head_node = head_node -> next;
    }
}   

int main() {

    Node* node = new Node(21, new Node(-15, new Node(-15, new Node(-7, new Node(15,NULL)))));

    Node* temp = node;

    while (temp != NULL)  {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }

    cout<<endl;

    solve(node);

    return 0;
}