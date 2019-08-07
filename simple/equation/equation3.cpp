#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
//并查集！！！！
using namespace std;

const int N = 30005;

//father 节点的父亲节点
//rank 节点的秩
int Father[N], Rank[N];

//查找节点x所在集合的根
//x 节点x
// 返回根
int find(int x) {
    
    if (x == Father[x]) {
        return x;
    }
    Father[x] = find(Father[x]);
    return Father[x];
}

//n 表示 变量个数 m表示约束个数 1 表示相等 0表示不相等  A大小为m 表示m约束中的a B大小为m 表示m约束中的b E大小为m 表示m约束中的e
string getAnswer(int n, int m, vector<int> A, vector<int> B, vector<int> E) {

    //初始化
    for (int i = 0; i <= n; i ++) {
        Father[i] = i;
        Rank[i] = 0;
    }

    //提前要进行交换
    /* blank */
    //首先把 “ = ” 的约束提到前面来
    int cns = 0;
    for (int i = 0; i < m; i ++) {
        if (E[i] == 1) {
            swap(A[i], A[cns]);
            swap(B[i], B[cns]);
            swap(E[i], E[cns]);
            cns += 1;
        }
    }

    for (int i = 0; i < m; i ++) {
        int setA = find(A[i]);
        int setB = find(B[i]);

        if (E[i] == 0) {
            if (setA == setB) {
                return "No";
            }
        } else {
                if (setA != setB) {
                    if (Rank[setA] > Rank[setB]) {
                        swap(setA, setB);
                    }
                    Father[setA] = setB;
                    if (Rank[setA] == Rank[setB]) {
                        Rank[setB] += 1;
                    }
                }
            }
        }
    return "Yes";

}

int main() {
    int N;
    cin>>N;//组数
    for (int i = 0; i < N; i ++) {
        int n;//变量个数
        int m;
        cin>>n>>m;
        vector<int> A;
        vector<int> B;
        vector<int> E;
        for (int j = 0; j < m; j ++) {
            //输入m条数据
            int a;
            int b;
            int e;
            cin>>a>>b>>e;
            A.push_back(a);
            B.push_back(b);
            E.push_back(e);
        }
        cout<<getAnswer(n, m, A, B, E);
    }
    return 0;
}