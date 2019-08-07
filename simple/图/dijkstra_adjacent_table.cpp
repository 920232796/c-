#include<bits/stdc++.h>

using namespace std;

#define INF 100000

typedef pair<int, int> P;

struct Edge {
    int cost = INF;
    int to;
};

priority_queue<P, vector<P>, greater<P> > q;

int N;//顶点数
int R;//边数
int dist[1000];

vector<Edge> G[1000];

void addEdge(int u, int v, int w) {
    G[u].push_back(Edge {w, v});
    G[v].push_back(Edge {w, u});
}

//s : 起始点
void solve(int s) {
    fill(dist, dist + N, INF);
    q.push(P(0, s));
    dist[s] = 0;

    while (!q.empty()) {

        //取出来第一个 也就是最小的了，然后循环它周围的节点，看看是否需要更新
        P min_p = q.top();
        q.pop();
        int d = min_p.first;//距离
        int v = min_p.second;//顶点
        for (int i = 0; i < G[v].size(); i ++) {
            //循环相连接的边
            Edge e = G[v][i];
            int d2 = d + e.cost;
 
            if (dist[e.to] > d2) {
                dist[e.to] = d2;
                q.push(P(d2, e.to));
            }
        }
        
    }
}

//邻接表 + 优先队列形式的最短路算法
int main() {
    cin>>N>>R;
  
    for (int i = 0; i < R; i ++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    solve(0);

    for (int j = 0; j < N; j ++) {
        cout<<dist[j]<<endl;
    }
    return 0;
}