/*
7 9
1 3 1
2 3 2
3 4 3
5 2 10
3 6 7
4 6 1
4 7 5
5 6 5
6 7 8
*/
////输入

#include<iostream>
using namespace std;

int cost[100][100]; //邻接矩阵
int d[100]; //用来保存每个点的最小距离
bool used[100]={false}; //初始化访问数组
int ans=0; //生成最小生成树边权的总值

int prim(int V)
{
    d[0]=0;
    for(int h=0;h<V;h++) //循环所有顶点
    {
        int min=100000; int u=-1; //u为最小距离顶点 min为最小距离
        for(int p=0;p<V;p++)
        {
            if(used[p]==false&&d[p]<min)
            {
                u=p;
                min=d[p];
            }
        }
        cout<<"u=="<<u<<endl;
        if (u==-1) return 0;
        used[u]=true;
        ans=ans+d[u];
        for(int m=0;m<V;m++)
        {
            if(used[m]==false&&cost[u][m]<d[m])  //以u为中介点进行优化
            d[m]=cost[u][m];  //特别注意跟迪杰斯特拉优化的区别！！
        }
    }
    return ans;
}

int main()
{
    int E,V; //E为边数 V是顶点数
    int from,to;
    cout<<"请输入边数E和顶点数V："<<endl;
    cin>>V;
    cin>>E;
    for(int m=0;m<100;m++)
    {
        for(int n=0;n<100;n++)
        {
            cost[m][n]=10000;
        }
    }
    cout<<"请输入各个顶点边的边权："<<endl;
    for(int i=0; i<E; i++) //注意是E！！
    {
        cin>>from;
        cin>>to;
        int cost1;
        cin>>cost1;
        // int cost2;
        // cin>>cost2;
        cost[from-1][to-1] = cost1;
        cost[to-1][from-1] = cost1;
    }

    for(int h=0;h<V;h++)
    {
        d[h]=10000; //初始化距离数组
    }

    prim(V);
    cout<<ans;
    return 0;
}