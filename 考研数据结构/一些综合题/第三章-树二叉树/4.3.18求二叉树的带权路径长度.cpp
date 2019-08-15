#include<iostream>
#include<queue>
#include<stack>

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

int wpl = 0;

void pre_order(Node* tree, int deep) {

    if (tree == NULL) {
        return ;
    }

    //前序遍历
    if (tree -> lchild == NULL && tree -> rchild == NULL) {
        wpl = wpl + deep * tree -> data;
    }

    pre_order(tree -> lchild, deep + 1);
    pre_order(tree -> rchild, deep + 1);
   
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

    pre_order(Tree, 1);

    cout<<"height = "<<wpl<<endl;


    return 0;
}