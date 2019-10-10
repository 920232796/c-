#include<iostream>
#include<math.h>
using namespace std;

void find(int tree[],int key,int n)
{
    for(int i=0;i<pow(2, n) - 1;i++)
    {
        cout<<"hello"<<endl;
        if(key==tree[i])
        {
            int j = i;
            // cout<<"hello";
            while((j-1)/2>0)
            {   

                cout<<tree[(j-1)/2]<<" ";
                // cout<<j<<endl;
                j=(j-1)/2;
            }
            cout<<tree[(j - 1) / 2]<<endl;
        }
        
    }
}

int main()
{
    int tree[15];
    tree[0]=1;
    tree[1]=2;tree[2]=3;
    tree[3]=4;tree[4]=5;
    tree[7]=6;
    tree[5]=-1;tree[6]=-1;tree[8]=-1;tree[9]=-1;
    tree[10]=-1;tree[11]=-1;tree[12]=-1;tree[13]=-1;tree[14]=-1;

    cout<<"请输入要找祖先的结点的值key：";
    int key;
    cin>>key;

    cout<<"请输入要构建二叉树的层次n：";
    int n;
    cin>>n;

    
    find(tree,key,n);
    int a = pow(2, 5);
    cout<<a<<endl;
    return 0;

}