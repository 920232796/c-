#include<iostream>

using namespace std;

#define MAX_X 10000
#define MAX_Y 10000
/*
5
6
1 2 5
1 3 1
3 4 2
2 4 1
2 5 2
4 5 4
*/
int N; //顶点数
int E; //边数
int cost[10000][10000]; //邻接矩阵
int d[10000];//最小距离
bool used[10000];

void dijkstra(int s) {

    fill(d, d + N, 10000);
    fill(used, used + N, false);
    d[s] = 0;

    while (true) {
        int v = -1;

        for (int i = 0; i < N; i ++) {
            if (!used[i] && (v == -1 || d[v] > d[i])) {
                v = i;
            }
        }

        cout<<v<<endl;

        if (v == -1) {
            break;
        }

        used[v] = true;

        for (int j = 0; j < N; j ++) {
            d[j] = min(d[j], d[v] + cost[v][j]);
        }
    }

    for (int j = 0; j < N; j ++) {
        cout<<"ii原点到节点 "<<j<<"i的最短路径为："<<d[j]<<endl;
    }
}

int main() {
    cin>>N;
    cin>>E;

    for (int i = 0; i < N; i ++) {
        fill(cost[i], cost[i] + N, 10000);
    }
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

    dijkstra(0);

    return 0;
}