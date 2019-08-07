#include<iostream>
#include<algorithm>
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

using namespace std;

#define MAX_N 1000

struct Edge {
    int from;
    int to;
    int cost;
};

bool comp(Edge e1, Edge e2) {
    return e1.cost < e2.cost;
}

Edge es[MAX_N];
int N; //顶点数
int E; //边数

class UnionFind {
    private:
        int father[MAX_N];
    
    public:
        void init(int n) {
            for (int i = 0; i < n; i ++) {
                father[i] = i;
            }
        }

        int find(int x) {
            if (x == father[x]) {
                //z证明找到父亲了!
                return x;
            }
            x = find(father[x]);
            return x;
        }

        bool merge(int x, int y) {
            //判断父亲一不一样
            int f_x = find(x);
            int f_y = find(y);
            if (f_x == f_y) {
                return false;
            }
            father[f_y] = f_x;
            return true;
        }

        bool same(int x, int y) {
            int f_x = find(x);
            int f_y = find(y);
            if (f_x == f_y) {
                return true;
            }
            return false;
        }
};



int main() {

    cin>>N;
    cin>>E;//边数
    for (int i = 0; i < E; i ++) {
        cin>>es[i].from;
        cin>>es[i].to;
        cin>>es[i].cost;
    }

    sort(es, es + E, comp);

    UnionFind uf;
    uf.init(N);

    int res = 0;

    for (int i = 0; i < E; i ++) {
        Edge e_min = es[i];
        if (uf.merge(e_min.from, e_min.to)) {
            // 合并成功
            res += e_min.cost;
        }
    }
    cout<<res<<endl;
    return 0;
}