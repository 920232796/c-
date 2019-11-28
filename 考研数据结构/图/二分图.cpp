#include<iostream>
using namespace std;
#include<queue>

queue<int> q; //定义一个存放顶点的队列
int G[100][100];
bool used[100]={false};

void BFS(int V)
{
    q.push(0);
    while(!q.empty())
    {
        int node = q.front();//取出来队头数据
        // cout<<node<<endl;
        used[node]=true;
        q.pop();//弹出来队头
        if(G[node][node]==0)
        {
            for(int p=0;p<V;p++)
            {   
                if (node == p) {
                    continue;
                }
                if(G[node][p]==1&&used[p]==true&&G[p][p]==0) //如果相连的点被访问过 且染色颜色相同
                {
                    cout<<"NO";
                    cout<<node<<p<<endl;
                    return;
                }
                else if(G[node][p]==1&&used[p]==false) //如果点没有被访问过 入队 染色
                {
                    q.push(p); //入队
                    G[p][p]=1; //染色
                    used[p]=true;
                }
            }
        }
        if(G[node][node]==1)
        {
            for(int p=0;p<V;p++)
            {   
                if (node == p) {
                    continue;
                }
                if(G[node][p]==1&&used[p]==true&&G[p][p]==1)
                {
                    cout<<"NO";
                    cout<<node<<p<<endl;
                    return ;
                }
                else if(G[node][p]==1&&used[p]==false)
                {
                    q.push(p);
                    G[p][p]=0;
                    used[p]=true; // zhuyi
                }
            }
        }

    }
    cout<<"YES";
}

int main()
{
    int V,E;
    int from,to;
    cout<<"请输入结点个数V和边数E：";
    cin>>V;
    cin>>E;
    cout<<"请输入相连的两条边：";
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            G[i][j]=0; //初始化不通为0
        }
    }

    for(int p=0;p<E;p++)
    {
        cin>>from;
        cin>>to;
        G[from-1][to-1]=1; //可通
        G[to-1][from-1]=1;
    }

    BFS(V);

    return 0;
}