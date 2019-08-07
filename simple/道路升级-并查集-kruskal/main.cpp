#include <bits/stdc++.h>

using namespace std;

const int N = 50005;

class UnionSet{

    public:
        int f[N];//每个节点的父亲节点
    
    //初始化 n为节点的数量
    void init(int n) {
        for (int i = 0; i < n; i ++) {
            f[i] = i;
        }
    }

    //路径压缩
    int find(int x) {
        if (x == f[x]) {
            return x;
        }
        f[x] = find(f[x]);
        return f[x];
    }

    //合并
    //将x 跟 y节点所在的集合 合并 返回true 表示成功合并  返回false 表示已经在一个集合里面了
    bool merge(int x, int y) {
        int setX = find(x);
        int setY = find(y);

        if (setX != setY) {
            f[setX] = setY;
            return true;
        }

        return false;
    }
} us;

vector<int> getAnswer(int n, int m, vector<int> U, vector<int> V) {
    vector<int> ans;
    us.init(n);
    for (int i = m - 1; i >= 0; --i) {
        if (us.merge(U[i], V[i])) {
            ans.push_back(i + 1);
        }
    }

    reverse(ans.begin(), ans.end());// ans 是从小到大排列的

    return ans;
}

int main() {

    cout<<"hello world" <<endl;
    return 0;
}