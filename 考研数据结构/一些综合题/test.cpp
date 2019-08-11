#include<iostream>
#include<map>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n) {
        data = d;
        next = n;
    }
};


int main() {

    Node* n = new Node(-1, new Node(-2, NULL));

    Node* head_n = n;

    n = n -> next;

    cout<<head_n -> data<<endl;

    return 0;
}