#include<iostream>
#include<queue>

using namespace std;

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
        cout<<temp_node -> data<<endl;
    }


}


int main() {

    Node* Tree = new Node(1, new Node(2, new Node(4, NULL, new Node(7, NULL, NULL)), NULL), 
    new Node(3, new Node(5, NULL, NULL), new Node(6, NULL, NULL)));

    bfs(Tree);
    return 0;
}