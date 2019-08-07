#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node (int d, Node* n) {
        data = d;
        next = n;
    }

};

struct LinkStack {
    Node* top = new Node(0, NULL);
    
    int count = 0;

    void push(Node* n) {
        count ++;
        if (top -> next != NULL) {
             n -> next = top -> next;
        }
       
        top -> next = n;
    }

    void pop() {
        count --;
        top -> next = top -> next -> next;   
    }

    void see() {
        while (top -> next != NULL) {
            cout<<top -> next -> data<<endl;
            pop();
        }
    }
} ;

int main() {

    LinkStack stack;
    Node* node = new Node(10, NULL);
    // node -> data = 10;
    stack.push(node);

    for (int i = 0; i < 10; i ++) {
        Node* node = new Node(i, NULL);
        stack.push(node);
    }

    cout<<"push之后栈元素个数：";
    cout<<stack.count<<endl;

    stack.see();

    cout<<"count after pop : "<<stack.count;

    // cout<<"你好 世界"<<endl;

    return 0;
}