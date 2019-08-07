#include<bits/stdc++.h>

using namespace std;

int N;//男生数
int M;//女生数
int E;//边数
int res = 0;

struct Edge {
    int cost = 0;
    int to;
    int from;
};

Edge ev[2000];

class UnionFind {
    public:

    int f[1000];

    void init() {
        for (int i = 0; i < N + M; i ++) {
            f[i] = i;
        }
    }

    int find(int x) {
        if (f[x] == x) {
            return x;
        } 

        return find(f[x]);
    }

    bool merge(int x, int y) {
        int setX = find(x);
        int setY = find(y);

        if (setX == setY) {
            return false;
        } 

        f[setX] = setY;
        return true;
    }

} uf;

bool comp(Edge e1, Edge e2) {
    return e1.cost < e2.cost;
}


int kruskal() {

    uf.init(); //并查集初始化
    sort(ev, ev + E, comp);

    // for (int i = 0; i < E; i ++) {
    //     cout<<ev[i].cost<<endl;
    // }

    for (int i = 0; i < E; i ++) {
        Edge e = ev[i];//取出最小的边

        if (uf.merge(e.from, e.to)) {
            //合并成功
            cout<<e.from<<endl;
            cout<<e.to - 5<<endl;
            cout<<"~~"<<endl;
            res += e.cost;
        }
    }

    // cout<<res<<endl;
    return res;

}

int main() {

    cin>>N>>M>>E;

    for (int i = 0; i < E; i ++) {
        int u, v, w;
        cin>>u>>v>>w;
        ev[i] = (Edge){-w, N + v, u};
    }

    // cout<<kruskal()<<endl;
    cout<<(N + M) * 10000 + kruskal()<<endl;


    return 0;
}