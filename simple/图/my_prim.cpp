#include<bits/stdc++.h>

using namespace std;

//prim 算法
const int MAX_V = 10;
const int V = 5; //顶点的个数
int cost[MAX_V][MAX_V]; //两个顶点之间的距离
bool used[MAX_V];//是否已经划入已探索部分
int mincost[MAX_V];// 保存当前范围到外侧范围顶点之间 最短的路径
vector<int> node;//记录路径

//不需要定义在哪出发 哪个点都可以~
int my_prim() {

    //初始化
    fill(used, used + V, false);
    fill(mincost, mincost + V, 10000);

    mincost[0] = 0;
    int res = 0;
    

    while (true) {

        
        int v = -1;

        for (int i = 0; i < V; i ++) {
            
            if (!used[i] && (v == -1 || mincost[v] > mincost[i])) {
                v = i; //选出来那个 连通两个区域之间 距离最小的 那个顶点
            }
        }

        if (v == -1) {
            break;
        }
        //选出来了v 所以现在要把v 归到 已经访问的范围
        // cout<<v<<endl;
        used[v] = true;
        node.push_back(v);
        res += mincost[v]; //计算结果

        //更新一下mincost数组才行！方便下次继续找出来距离最小的那个顶点

        for (int i = 0; i < V; i ++) {

            mincost[i] = min(mincost[i], cost[v][i]);
        }

    }

    return res;

}


int main() {
    //初始化把所有的边都设置成很大 表示不可达
    for (int i = 0; i < V; i ++) {
        fill(cost[i], cost[i] + V, 10000);
    }

    cost[0][1] = 5;
    cost[0][2] = 1;
    cost[2][3] = 2;
    cost[1][3] = 1;
    cost[1][4] = 2;
    cost[3][4] = 4;

    cost[1][0] = 5;
    cost[2][0] = 1;
    cost[3][2] = 2;
    cost[3][1] = 1;
    cost[4][1] = 2;
    cost[4][3] = 4;

    int res = my_prim();

    cout<<"res = "<<res<<endl;
    cout<<"node = ";
    for (int i = 0; i < node.size(); i ++) {
        cout<<node[i]<<" ";
    }
    return 0;
}