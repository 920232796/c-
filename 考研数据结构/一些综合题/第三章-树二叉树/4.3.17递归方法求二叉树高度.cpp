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

// int 表示返回深度
int solve(Node* tree) {

    if (tree == NULL) {
        return 0;
    } 
    //否则的话 求左右子树的高度
    int l_deep = solve(tree -> lchild);
    int r_deep = solve(tree -> rchild);

    if (l_deep > r_deep) {
        return l_deep + 1;
    } else {
        return r_deep + 1;
    }
}

queue<Node*> q;

void bfs(Node* tree) {

    q.push(tree);

    while (!q.empty()) {
        Node* temp_node = q.front();
        q.pop();
        if (temp_node != NULL) {
            q.push(temp_node -> lchild);
       
            q.push(temp_node -> rchild);

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