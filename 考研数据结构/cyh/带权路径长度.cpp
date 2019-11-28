#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* lchild;
    Node* rchild;

    Node(int d, Node* l, Node* r)
    {
        data = d;
        lchild = l;
        rchild = r;
    }
};

int cost=0; //带权路径长度
int find_wpl(Node* Tree,int floor)
{
    Node* temp=Tree;
    if(temp->lchild!=NULL&&temp->rchild!=NULL)
    {
        find_wpl(temp->lchild,floor+1);
        find_wpl(temp->rchild,floor+1);
    }
    else
    {
        cost=cost+floor*temp -> data;
    }
    
    return cost;

}

int main()
{
    int floor=1;
    Node* Tree = new Node(14, new Node(5, new Node(1, NULL, NULL), new Node(4, NULL, NULL)),
                          new Node(9, NULL, NULL));

    int result=find_wpl(Tree,floor);
    cout<<result;

    return 0;
}