#include<iostream>

using namespace std;

int G[100][100];
int N;//顶点数
int E;//边数
int d[100]; //d[j]表示从起点到 第j个点的最短距离

void solve() {

    //初始化
    for (int i = 0; i < N; i ++) {
        d[i] = 10000;
    }
    d[0] = 0;
    for (int i = 0; i < N; i ++) {
        for (int j = 1; j < N; j ++) {
            d[j] = min(d[j], d[i] + G[i][j]);
        }
    }
    for (int i = 0; i < N; i ++) {
        cout<<d[i]<<" ";
    }
    return ;
}

int main() {
    cin>>N;
    cin>>E;
    for (int i = 0; i < E; i ++) {
        int s, t, c;
        cin>>s; //从哪点
        cin>>t; //到哪个点
        cin>>c; //cost 花费

        G[s][t] = c;
    }

    solve();

    return 0;
}