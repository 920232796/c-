#include<iostream>

using namespace std;

int n; // n个字符

struct stack {
    char data[100];
    int top = -1;

    void insert(char c) {
        data[++top] = c;
    }
    char get_top() {
        char res = data[top];
        return res;
    }
    void pop() {
        top --;
        return ;
    }

};

struct Node {
    char data;
    Node* next;

    Node(char c, Node* n) {
        data = c;
        next = n;
    }
};

bool judge(Node* node) {

    stack s;
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i ++) {
            s.insert(node -> data);
            node = node -> next;
        }
    } else if (n % 2 != 0) {
        for (int i = 0; i < n / 2 + 1; i ++) {
            s.insert(node -> data);
            node = node -> next;
        }
        s.pop();
    }
    // int len = s.top;
    // while (len != -1) {
    //     cout<<s.data[len]<<" ";
    //     len --;
    // }

    while (node != NULL) {
        if (s.get_top() != node -> data) {
            //不是中心对称
            
            return false;
        } else {
            s.pop();
            node = node -> next;
        }
    }

    return true;

}


int main() {

    Node* node = new Node('x', new Node('y', new Node('x', new Node('x', new Node('y', new Node('x', NULL))))));
    n = 6;

    Node* temp = node;

    while (temp != NULL) {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }

    cout<<endl;

    if (judge(node)) {
        cout<<"YES"<<endl; 
    } else {
        cout<<"NO"<<endl;
    }

    return 0;
}