#include<bits/stdc++.h>

using namespace std;

const int Max_E = 50;
const int Max_V = 50;

struct edge {
    int from;
    int to;
    int cost;
};

//所有边的信息，需要输入进去
edge es[Max_E];
int d[Max_V];
int V, E;

// 参数s 就是从哪出发 最后会求出来从s出发 到所有点的最短距离
void shortestPath(int s) {
    //初始化
    for (int i = 0; i < Max_V; i ++) {
        d[i] = 10000;
    }
    d[s] = 0;//初始点 距离为0

    while (true) {

        bool update = false;
        for (int j = 0; j < E; j ++) {
            //对每条边都更新
            edge e = es[j];
            if (d[e.from] != INFINITY && d[e.from] + e.cost < d[e.to]) {
                //说明需要更新了，也就是得松弛了
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) {
            break;
        }
    }
    for (int k = 0; k < V; k ++) {
        printf("顶点 %d 的最短长度为: %d\n", k, d[k]);
    }
}

int main() {
    V = 5;
    E = 6;
    es[0].from = 0;
    es[0].to = 1;
    es[0].cost = 5;

    es[1].from = 1;
    es[1].to = 4;
    es[1].cost = 2;

    es[2].from = 0;
    es[2].to = 2;
    es[2].cost = 1;

    es[3].from = 2;
    es[3].to = 3;
    es[3].cost = 2;

    es[4].from = 3;
    es[4].to = 1;
    es[4].cost = 1;

    es[5].from = 3;
    es[5].to = 3;
    es[5].cost = 4;

    shortestPath(0);
    printf("hello wolrd");
    return 0;
}

