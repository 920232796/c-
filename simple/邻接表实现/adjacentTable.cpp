#include<bits/stdc++.h>

using namespace std;

// #define Max_V 20

// int Max_V = 20;
const int Max_V = 30;
vector<int> G[Max_V]; //G 数组 数组中每个元素都是vector 然后第0个元素就代表 第0个顶点 往里面push的都是跟第0个顶点相连的顶点


int main() {

    for (int i = 0; i < 5; i ++) {
        //五条边
        int s, t;
        scanf("%d %d", &s, &t);
        G[s].push_back(t);//从s 连接到 t
        G[t].push_back(s);//t 连接到 s  无向图

    }

    for (int j = 0; j < Max_V; j ++) {
        for (int k = 0; k < G[0].size(); k ++) {
            printf("%d", G[j][k]);
        }
        printf("\n");
    }

    // printf("hello world;");
    return 0;
}