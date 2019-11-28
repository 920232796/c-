#include<iostream>

using namespace std;

typedef struct LNode
{
    int data;
    struct LNode* next;
} LNode;

void Init(int a[],int n,LNode* head)
{
    LNode* p=head; //工作指针
    for(int i=0; i<n; i++)
    {
        LNode* temp=((LNode*)malloc(sizeof(LNode)));
        temp->data=a[i];
        p->next=temp;
        p=p->next;
    }
    p->next=NULL; //别漏

}

void invert(LNode* head)
{
    LNode* rear=head;
    while(rear->next!=NULL)
    {
        rear=rear->next;  //先把rear定位到单链表的最后一个结点
    }
//    LNode* end=rear;
//    LNode* temp3=head->next;
//    head->next=head->next->next;
//    end->next=temp3;
    while(head->next!=rear)
    {
        LNode* temp2=head->next;
        head->next=head->next->next; //删除已经逆置的结点
        temp2->next=rear->next;
        rear->next=temp2;
//        end=end->next;
    }
//    end->next=NULL;

}

int main()
{
    LNode* head=((LNode*)malloc(sizeof(LNode)));
    head->next=NULL; //头指针
    int n,a[20];
    cout<<"请输入数字个数n："<<endl;
    cin>>n;
    cout<<"请输入数字："<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    Init(a,n,head);
    invert(head);

    while(head->next!=NULL) //永远不要用head!=NULL
    {
        cout<<head->next->data<<' ';
        head=head->next;
    }

    return 0;

}