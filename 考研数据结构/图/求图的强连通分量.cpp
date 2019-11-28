#include<iostream>
#include<stack>
/*
6 8
2 3
1 2
1 4
3 6
4 5
2 5
5 1
5 6
output:
6
5
3 4 2 1
*/
using namespace std;

int G[100][100];
bool used[100];
int N, E;
int low[100]; //存 跟这个点 最早相连通的点
int dfn[100];// 存 index ，表示了 访问的先后
int index1 = 0;

stack<int> s;

void dfs(int u) {
    // u 为出发点，表示从哪个点开始进行dfs
    //先入栈
    s.push(u);
    // cout<<"u: "<<u<<endl;
    low[u] = index1;
    dfn[u] = index1;
    index1 ++;
    used[u] = true;
    //再去遍历周围的边，继续dfs;
    for (int v = 0; v < N; v ++) {
        if (v == u) {
            continue;//跳过自己
        }
        //如果没有访问过，再去dfs，如果已经访问过了，那么就证明发现了连通分量～可以修改low的数值了
        if (!used[v] && G[u][v] == 1) {
            dfs(v);

            //dfs完事之后，我们需要修改一下low的数值，维持一种谁是谁的子节点的关系，如果不修改low，等下面的代码会判断low跟dfn
            //不修改low，则每次都会进入下面代码的if，不行～
            low[u] = min(low[u], low[v]); //取一个更小的～

        } else if (used[v] && G[u][v] == 1) {
            //表示已经访问过，但是还有路，说明找到了连通的点了～
            low[u] = min(low[u], dfn[v]);//取一个更小的～ 不过我感觉也可以换成low[v]而不用dfn[v]
            // low[u] = min(low[u], low[v]);// 用这个结果也一样～～
        }
    }

    int res[100];
    int i = 0;
    // cout<<low[0]<<"~~~"<<endl;
    // cout<<dfn[0]<<"~~~~"<<endl;
    // if (u == 0) {
    //     cout<<"hello"<<endl;
    // }
    // if (u == 2) {
    //     cout<<"u==2"<<low[u]<<dfn[u]<<endl;
    // }
    //到这 要比较一下 low[u] dfn[u] 如果相等，则要弹出栈中这个节点之后的所有节点，因为这些节点都是连通的！！
    if (low[u] == dfn[u]) {
        // cout<<low[0]<<"~~~"<<endl;
        int p = s.top();
        res[i] = p;
        i ++;
        s.pop();
        
        while (p != u) {
            p = s.top();
            res[i] = p;
            i ++;
            s.pop();

        }
        //弹出的都是最后要输出的结果 现在要打印一下～
        for (int j = 0; j < i; j ++) {
            cout<<res[j]<<" ";
        }
        cout<<endl;
    }

}

int main() {

    cin>>N>>E;//输入顶点数，边数

    for (int i = 0; i < N; i ++) {
        used[i] = false;
        for (int j = 0; j < N; j ++) {
            G[i][j] = 0; //初始化不通
        }
    }   

    //输入图
    for (int i = 0; i < E; i ++) {
        int from;
        int to;
        cin>>from>>to;
        G[from - 1][to - 1] = 1;
    }

    dfs(0);



    return 0;
}   