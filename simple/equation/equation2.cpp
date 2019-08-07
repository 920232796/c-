#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
//set解决！！ 启发式合并
using namespace std;

const int N = 500003;

vector<int> Set[N];

//n 表示 变量个数 m表示约束个数 1 表示相等 0表示不相等  A大小为m 表示m约束中的a B大小为m 表示m约束中的b E大小为m 表示m约束中的e
string getAnswer(int n, int m, vector<int> A, vector<int> B, vector<int> E) {
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
    
    //先对n个变量都设id
    int ID[n+1];
    for (int i = 1; i <= n; i ++) {
        ID[i] = i;
    }


    for (int l = 0; l < n; l ++) {
        Set[l].push_back(ID[l + 1]);
    }

    //Set方法 两个for 循环
    for (int i = 0; i < m; i ++) {
        if (E[i] ==  1) {//证明这两个变量相等，那么证明应该位于同一个集合
            int ida = ID[A[i]];
            int idb = ID[B[i]];

            if (Set[ida].size() < Set[idb].size()) {
                //交换 a b 
                swap(ida, idb);
            }
            for (int k = 0; k < int(Set[idb].size()); k ++) {
                int c = Set[idb][k];
                Set[ida].push_back(c);
                ID[c] = ida;
            }
            
        } else if (E[i] == 0) {
            //证明不相等 判断是否在同一个集合中！
            if (ID[A[i]] == ID[B[i]]) {
                return "No";
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