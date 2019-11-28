#include<iostream>

using namespace std;
int cost[10000][10000]; //邻接矩阵
int d[10000];//最小距离
bool used[10000];

void Dijstra(int N,int source)
{
     d[source]=0;
     for(int k=0;k<N;k++) //循环所有顶点
     {
         int min=10000;
         int u=-1; //用来保存顶点的
         for(int p=0;p<N;p++) //每次寻找未访问过的距离最小的进行访问
         {
             if(used[p]==false&&d[p]<min)
             {
                 min=d[p];
                 u=p; //最小结点
                 
             }
         }
         cout<<u<<endl;
         used[u]=true;
         for(int k=0;k<N;k++)
         {
             if(d[u]+cost[u][k]<d[k])
             {
                 d[k]=d[u]+cost[u][k];
             }
         }
         if (u == 0) {
             cout<<d[1]<<endl;
             cout<<d[2]<<endl;
         }

     }
}

int main()
{
    int source;
    int N,E;
    cout<<"请输入顶点数和边数："<<endl;
    cin>>N;
    cin>>E;
    
    for (int i = 0; i < N; i ++)
    {
        fill(cost[i], cost[i] + N, 10000);
        d[i] = 10000;
    }

    for(int j=0;j<N;j++)
    {
        used[j]=false;  //初始化访问数组
    }

    cout<<"请分别输入起点、终点和距离："<<endl;
    for (int i = 0; i < E; i ++) {
        //注意输入from to 的时候 下标从1开始噢
        int a;
        int b;
        int cur_cost;
        cin>>a;
        cin>>b;
        cin>>cur_cost;

        cost[a - 1][b - 1] = cur_cost;
        cost[b - 1][a - 1] = cur_cost;
    }

    cout<<"请输入起点："<<endl;
    cin>>source;

    Dijstra(N,source);

    for(int j=0;j<N;j++)
    {
        cout<<d[j];
    }
    return 0;
}