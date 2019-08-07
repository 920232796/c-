#include<bits/stdc++.h>

using namespace std;

const int MAX_V = 10;

int cost[MAX_V][MAX_V];//边的权值 临界矩阵s实现
int V; //顶点数
bool used[MAX_V];//顶点是否已经走过
int d[MAX_V];//从顶点出发的最短距离
int pre[MAX_V];//定义前驱节点，为了进行路径还原 

//s : 从哪点出发
void dijkstra(int s) {

    //初始化每个顶点，赋值成很大
    fill(d, d + V + V, 1000);
    // fill(d, d + V, 10000);
    fill(used, used + V, false);
    fill(pre, pre + V, -1);

    d[s] = 0;

    while (true) {

        int v = -1;
        //循环每一个顶点 找出d 最小的那个
        for (int i = 0; i < V; i ++) {
            if (!used[i] && (v == -1 || d[v] > d[i])) {
                //找到了一个最小的顶点
                v = i;
            }
        }

        if (v == -1) {
            break;
        }

        //这个最短d的顶点 已经走过 标记一下
        used[v] = true;


        //因为找到了一个d最小的 因此就根据这个最小的d 去更新其余的顶点，然后下次循环再从剩余没被使用过的顶点里面再去选最小的，更新d
        //一直到 所有的点都被使用过了，所以就退出循环了.
        for (int j = 0; j < V; j ++) {
            d[j] = min(d[j], d[v] + cost[v][j]);
            if (d[j] == d[v] + cost[v][j]) {
                //添加前驱节点
                pre[j] = v;
            }
        }

    }

    for (int k = 0; k < V; k ++) {

        printf("顶点 %d 的最短路径长度为 %d\n", k, d[k]);
    }

}

int main() {

    V = 5;
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


    dijkstra(0);

    //z找一下最后节点为 4 的时候，最短路径是什么
    int node = 4;
    string path = "" + to_string(node);

    while (true) {
        if (node != 0) {
            path += " ";
            path += to_string(pre[node]);
            node = pre[node];
        } else {
            break;
        }
    }

    // printf("path = %*s\n", path);
    cout<<"path = "<<path<<endl;

    // printf("hello wolrd");
    return 0;
}