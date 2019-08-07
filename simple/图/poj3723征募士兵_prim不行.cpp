#include<bits/stdc++.h>

//最小生成树问题！  本地的图是不连通的 所以 prim算法 好像不可以。。
//但是使用 kruskal算法 就可以得出不连通图的最小生成树！
using namespace std;

#define INF 10000

int N;//定点数
int R;//边数
bool used[1000];

typedef pair<int, int> P;

priority_queue<P, vector<P>, greater<P> > q;

int res = 0;

struct Edge {
    int cost = 0;
    int to;
};

vector<Edge> G[1000];

void addEdge(int u, int v, int w) {
    G[u].push_back(Edge{w, v});
    G[v].push_back(Edge{w, u});
}

void prim(int s) {

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < G[i].size(); j++) {
            q.push(P(G[i][j].cost, G[i][j].to));
        }
    }
}

int main() {

    cin>>N>>R;
    
    for (int j = 0; j < R; j ++) {
        int u, v, w;
        cin>>u>>v>>w;
        addEdge(u, v, -w);
    }

    prim(0);

    return 0;
}