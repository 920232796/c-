#include<iostream>
#include<stack>
using namespace std;

bool used[100]= {false};
int G[100][100]; //初始化-1代表不能走
int low[100]= {0};  //连通分量数组
int dfn[100]={0};  //代表DFS的步数
int index1 = 0;
stack<int> s;

void DFS(int x,int V)
{
    s.push(x);
    low[x]=index1;
    dfn[x]=index1;
    index1 ++;
    used[x]=true;

    for(int j=0; j<V; j++)
    {
        if(G[x][j]!=-1&&used[j]==false) //如果有路可以走并且这个点没有被走过
        {
//            push(j);
//            used[j]=true; //让没走过的点入栈并设置已经访问
//            low[j]=low[j]+1;
            DFS(j,V);//接着走DFS
            low[x]=min(low[j],low[x]); //这个min的内置函数怎么写来着
            
        }
        else if(G[x][j]!=-1&&used[j]==true)
        {
            low[x]=min(low[j],low[x]);
        }
    }
    
    if(low[x]==dfn[x])
    {
        
        int p = s.top();
        s.pop();
        cout<<p<<" ";

        while(p != x) {
            p = s.top();
            s.pop();
            cout<<p<<" ";
        }
        cout<<endl;
    }
    
   
    

}

int main()
    {   
        
        int from,to;
        int V,E;
        cout<<"请输入顶点的个数V和边数E";
        cin>>V;
        cin>>E;
        //初始化G
        for (int i = 0; i < V; i ++) {
            for (int j = 0; j < V; j ++) {
                G[i][j] = -1;
            }
        }
        cout<<"请输入相连的两个顶点from到to";
        for(int i=0; i<E; i++)
        {
            cin>>from;
            cin>>to;
            G[from-1][to-1]=1;
        }

        DFS(0,V);
        
        return 0;
    }