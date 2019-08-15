#include<iostream>
#include<queue>
#include<stack>

using namespace std;

//正向层次遍历 + 栈 反向输出

struct Node {
    int data;
    Node* lchild;
    Node* rchild;

    Node(int d, Node* l, Node* r) {
        data = d;
        lchild = l;
        rchild = r;
    }
};

queue<Node*> q;
stack<Node*> s;

void bfs(Node* tree) {

    q.push(tree);

    while (!q.empty()) {
        Node* temp_node = q.front();
        q.pop();
        if (temp_node -> lchild != NULL) {
            q.push(temp_node -> lchild);
        } 
        if (temp_node -> rchild != NULL) {
            q.push(temp_node -> rchild);
        }
        s.push(temp_node);
    }

    while (!s.empty()) {
        cout<<s.top() -> data<<" ";
        s.pop();
    }

}


int main() {

    Node* Tree = new Node(1, new Node(2, new Node(4, NULL, new Node(7, NULL, NULL)), NULL), 
    new Node(3, new Node(5, NULL, NULL), new Node(6, NULL, NULL)));

    bfs(Tree);
    return 0;
}