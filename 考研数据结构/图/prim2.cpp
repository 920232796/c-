#include<iostream>
using namespace std;

int cost[100][100]; //邻接矩阵
int d[100]; //用来保存每个点的最小距离
bool used[100]={false}; //初始化访问数组
int ans=0; //生成最小生成树边权的总值

// c``````


int prim(int V)
{
    d[0]=0;
    for(int h=0;h<V;h++) //循环所有顶点
    {   
        // cout<<"hello world"<<endl;
        int min=10000; int u=-1; //u为最小距离顶点 min为最小距离
        for(int p=0;p<V;p++)
        {
            if(used[p]==false&&d[p]<min)
            {
                u=p;
                min=d[p];
                // cout<<u<<endl;
            }
            // cout<<"u = "<<u<<endl;
        }
        if (u==-1) return 0;
        used[u]=true;
        ans=ans+d[u];
        // cout<<"du = "<<d[u]<<endl;
        for(int l=0;l<V;l++)
        {
            if(used[l]==false&&cost[u][l]<d[l]){
                 d[l]=cost[u][l];  //特别注意跟迪杰斯特拉优化的区别！！
                //  cout<<"d[l]="<<d[l]<<endl;
            } //以u为中介点进行优化
           
        }
    }
    return ans;
}

int main()
{
    int E,V; //E为边数 V是顶点数
    int from,to;
    cout<<"请输入边数E和顶点数V："<<endl;
    cin>>E;
    cin>>V;
    for(int m=0;m<100;m++)
    {
        for(int n=0;n<100;n++)
        {
            cost[m][n]=1000;
        }
    }
    cout<<"请输入各个顶点边的边权："<<endl;
    for(int i=0; i<V; i++)
    {
        cin>>from;
        cin>>to;
        int cost11;
        cin>>cost11;
        cost[from-1][to-1] = cost11;
        // cost[to - 1][from - 1] = cost11;
    }

    for(int h=0;h<V;h++)
    {
        d[h]=1000; //初始化距离数组
    }

    prim(V);
    cout<<ans;
    return 0;
}