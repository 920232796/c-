#include<bits/stdc++.h>

using namespace std;

const int MAX_NODE = 1000;

int V, E; //顶点跟边数 

//边的结构体 从哪个顶点到哪个顶点，路径消耗是多少，这三个变量
struct edge {
    int u, v, cost;

    // edge(int a, int b, int c): u(u), v(b), cost(c) {};
};

edge es[MAX_NODE];

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

class UnionFind {
    public:

    int father[MAX_NODE];
    
    //并查集初始化
    void init() {
        for (int i = 0; i < MAX_NODE; i ++) {
            father[i] = i;
        }
    }
    //z找父节点
    int find(int x) {
        if (x == father[x]) {
            //证明找到父节点了
            return x;
        }
        father[x] = find(father[x]);
        return father[x];
    }

    bool merge(int x, int y) {
        
        int setX = find(x);
        int setY = find(y);
        if (setX != setY) {
            //证明父亲不一样 可以合并
            father[setX] = setY;
            return true;
        } else {
            return false;
        }

    }
} uf;

//看看两个顶点是否在同一个 区域内
bool same(int u, int v) {
    int setU = uf.find(u);
    int setV = uf.find(v);

    if (setU == setV) {
        return true;
    } else {
        return false;
    }
}

int kruskal() {
    sort(es, es + E, comp);//先排序 从cost最小到cost最大

    uf.init();//初始化并查集
    int res = 0;

    for (int i = 0; i < E; i ++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            //证明可以合并
            uf.merge(e.u, e.v);
            res += e.cost;
        }
    }

    return res;

}

int main() {
    
    es[0].cost = 1;
    es[0].u = 1;
    es[0].v = 3;

    es[1].cost = 2;
    es[1].u = 2;
    es[1].v = 3;

    es[2].cost = 3;
    es[2].u = 3;
    es[2].v = 4;

    es[3].cost = 10;
    es[3].u = 2;
    es[3].v = 5;

    es[4].cost = 7;
    es[4].u = 3;
    es[4].v = 6;

    es[5].cost = 1;
    es[5].u = 4;
    es[5].v = 6;

    es[6].cost = 5;
    es[6].u = 4;
    es[6].v = 7;

    es[7].cost = 5;
    es[7].u = 5;
    es[7].v = 6;

    es[8].cost = 8;
    es[8].u = 6;
    es[8].v = 7;

    V = 7;
    E = 9;

    int res = kruskal();

    cout<<res<<endl;

    return 0;
}

