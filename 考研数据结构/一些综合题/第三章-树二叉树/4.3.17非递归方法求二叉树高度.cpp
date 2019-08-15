#include<iostream>
#include<queue>
#include<stack>

//last 变量表示每一层最后一个结点 如果遍历到这个地方 那么深度就 加 1

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

// int 表示返回深度
int solve(Node* tree) {

    if (tree == NULL) {
        return 0;
    }
    int front = -1;
    int rear = 0;
    int last = 0;
    int level = 0;
    q.push(tree);

    while (!q.empty()) {
        Node* t = q.front();
        q.pop();
        front ++;

        if (t -> lchild != NULL) {
            q.push(t -> lchild);
            rear ++;
        }
        if (t -> rchild != NULL) {
            q.push(t -> rchild);
            rear ++;
        }

        if (front == last) {
            level ++;
            last = rear;// front == last 证明 遍历到一层最后一个结点了！ 那么深度+ 1 并且标记这最后一个结点的下层的最后结点为新的最后一个结点
        }

    }

    return level;
   
}

queue<Node*> qq;

void bfs(Node* tree) {

    qq.push(tree);

    while (!qq.empty()) {
        Node* temp_node = qq.front();
        qq.pop();
        if (temp_node != NULL) {
            qq.push(temp_node -> lchild);
       
            qq.push(temp_node -> rchild);

            cout<<temp_node -> data<<" ";
        } else {
            cout<<"null"<<" ";
        }
     
        
    }

    cout<<endl;

}


int main() {

    Node* Tree = new Node(1, new Node(2, new Node(4, NULL, new Node(7, NULL, NULL)), NULL), 
    new Node(3, new Node(5, NULL, NULL), new Node(6, NULL, NULL)));

    bfs(Tree);

    int height = solve(Tree);

    cout<<"height = "<<height<<endl;


    return 0;
}