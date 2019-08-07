#include<iostream>

using namespace std;

#define MAX_X 10000
#define MAX_Y 10000

/*
7
9
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

int N; //顶点数
int E; //边数
int cost[MAX_X][MAX_Y]; //邻接矩阵
int d[MAX_X];//最小距离
bool used[MAX_X];
int res = 0;

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

        // cout<<v<<endl;

        if (v == -1) {
            break;
        }

        used[v] = true;
        res += d[v];

        for (int j = 0; j < N; j ++) {
            d[j] = min(d[j], cost[j][v]);
        }
    }
    
    cout<<res<<endl;

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

    // for (int i = 0; i < N; i ++) {
    //     for (int j = 0; j < N; j ++) {
    //         cout<<cost[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    dijkstra(0);

    return 0;
}