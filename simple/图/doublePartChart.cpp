#include<bits/stdc++.h>

using namespace std;

//二分图判定
vector<int> G[5];
int color[5];

void consTable(int numberV, int numberE) {
    
    for (int i = 0; i < numberE; i ++) {
        //五条边
        int s, t;
        scanf("%d %d", &s, &t);
        G[s].push_back(t);//从s 连接到 t
        G[t].push_back(s);//t 连接到 s  无向图

    }

    for (int j = 0; j < numberV; j ++) {
        printf("%d ~ ", j);
        for (int k = 0; k < G[0].size(); k ++) {
            printf("%d ", G[j][k]);
        }
        printf("\n");
    }

}

//深度优先搜索
bool dfs(int v, int c) {
    color[v] = c;//将 顶点v染成c  c = 1 || c = -1
    //循环相邻节点 看看颜色
    for (int i = 0; i < G[v].size(); i ++) {
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) {
            return false ;
        }
        if (color[G[v][i]] == c) {
            //证明颜色一样了
            return false ;
        } 
    }
    return true ;
}

int main() {


    int numberV = 3;
    int numberE = 3;
    consTable(numberV, numberE);
    
    for (int i = 0; i < numberV; i ++) {
        //循环每一个顶点
        if (color[i] == 0) {
            //z证明这个顶点没有被染色
            if (!dfs(i, 1)) {
                printf("No");
                return 0;
            }
        }
    }

    printf("Yes");
    return 0;
}