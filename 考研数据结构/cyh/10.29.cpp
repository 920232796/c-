#include<iostream>

using namespace std;

typedef struct Lnode
{
    int data;
    struct Lnode* next;
} Lnode;

void Init(int a[],Lnode* head,int n)
{
    Lnode* temp=head;
    for(int i=0; i<n; i++)
    {
        Lnode* p=((Lnode*)malloc(sizeof(Lnode)));
        p->data=a[i];
        temp->next=p;
        temp=temp->next;
    }
    temp->next=NULL;
}
int result[100];

int add_sort(Lnode* head,int n)
{
    for(int i=0; i<n - 1; i++)
    {
        Lnode* r,*front; //存每次比较数最大的结点与最大结点的前驱结点
        Lnode* p=head->next;
        Lnode* ppr=head;//工作指针与它的前驱指针
        r=head->next;
        front=head;
        while(p->next!=NULL)
        {
            if(r->data>p->next->data)
            {
                p=p->next;
                ppr=ppr->next;
            }
            else
            {
                r=p->next;
                front=ppr->next;
                p=p->next;
                ppr=ppr->next;
            }

        }
        result[i]=r->data;
        
        front->next=r->next;

    }
    // head->next->data=result[n-1];
    // cout<<head -> data<<endl;
    // cout<<head -> next -> data<<endl;
    result[n - 1] = head -> next -> data;
}

int main()
{
    int a[100],n;
    cout<<"请输入要输入数字的个数n：";
    cin>>n;
    cout<<"请输入数字：";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    Lnode *head=((Lnode*)malloc(sizeof(Lnode)));
    head->next=NULL;

    Init(a,head,n);
    add_sort(head,n);

    for(int i=0; i<n; i++)
    {
        cout<<result[i]<<endl;
    }

//    while(head->next!=NULL)
//    {
//        cout<<head->next->data;
//        head=head->next;
//    }
    return 0;
}