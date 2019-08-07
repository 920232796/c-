#include<bits/stdc++.h>

using namespace std;

const int MAX_V = 10;

int cost[MAX_V][MAX_V];//边的权值 临界矩阵s实现
int d[MAX_V][MAX_V];//d[i][j]

int main() {
    int V = 5;
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

    for (int i = 0; i < V; i ++) {
        for (int j = 0; j < V; j ++) {
            d[i][j] = cost[i][j];
        }
        d[i][i] = 0;
    }

    for (int k = 0; k < V; k ++) {
        for (int i = 0; i < V; i ++) {
            for (int j = 0; j < V; j ++) {
                d[i][j] = min(d[i][j], d[i][k] + d[j][k]);
            }
        }
    }

    for (int i = 0; i < V; i ++) {
        for (int j = 0; j < V; j ++) {
            printf("i = %d, j = %d, d = %d \n", i, j, d[i][j]);
        }
    }

    return 0;
}