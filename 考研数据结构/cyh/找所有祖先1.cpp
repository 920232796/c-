#include<iostream>
using namespace std;

int find_number(int a[],int x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            return i;
        }
    }
}

void find_ancester(int a[],int n,int number)
{
    while(number>0)
    {
        number=(number-1)/2;
        cout<<number;
    }
}

int main()
{
    int n,a[100],x;
    cout<<"请输入树的结点个数：";
    cin>>n;
    cout<<"请输入树的结点中的树（空结点用-1表示）：";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"请输入要找祖先的结点的数字：";
    cin>>x;

    int number=find_number(a,x,n);

    find_ancester(a,n,number);
    return 0;

}