#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<vector>

using namespace std;

#define MAX_N 1000

typedef pair<int, int> P;
int N; //顶点数
int E;//边数

priority_queue<P, vector<P>, greater<P> > q;

struct Edge {
    int to;
    int cost;
    Edge(int t, int c) {
        to = t;
        cost = c;
    }
};

vector<Edge> G[MAX_N];

void add_edge(int u, int v, int cost) {
    G[u].push_back(Edge(v, cost));
    G[v].push_back(Edge(u, cost));
}

int dist[MAX_N];

void dijkstra(int s) {

    fill(dist, dist + N, 10000);
    dist[s] = 0;
    q.push(P(0, s));


    while (!q.empty()) {
        P edge = q.top();
        q.pop();
        int from = edge.second;
        int cost = edge.first;

        for (int i = 0; i < G[from].size(); i ++) {
            int d = cost + G[from][i].cost; //这个d是关键，记录了 从起点到此点的最短距离
            if (d < dist[G[from][i].to]) { 
                dist[G[from][i].to] = d;
                q.push(P(d, G[from][i].to));

            }
        }
   }

   for (int i = 0; i < N; i ++) {
       cout<<i<<" "<<dist[i]<<endl;
   }
}

int main() {

    cin>>N;
    cin>>E;

    for (int i = 0; i < E; i ++) {
        int u;
        int v;
        int cost;

        cin>>u;
        cin>>v;
        cin>>cost;

        add_edge(u - 1, v - 1, cost);

    }

    cout<<endl;

    dijkstra(0);

    // for (int i = 0; i < N; i ++) {
    //     for(int j = 0; j < G[i].size(); j++) {
    //         cout<<i<<" "<<G[i][j].to<<" "<<G[i][j].cost<<endl;
    //     }
    // }

    return 0;
}