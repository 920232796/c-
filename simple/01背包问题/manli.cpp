#include <bits/stdc++.h>

using namespace std;

int n;
int w[100];
int v[100];
int W;

//蛮力算法， i表示第i个物品  j表示还有多少空间
int solve(int i, int j, int n) {

    int res;
    if (n == i) {
        //证明没有物品了
        return res = 0;

    } else if (j < w[i]) {
        //证明放不下这个物品
        res = solve(i + 1, j, n);
    } else {
        res = max(solve(i + 1, j - w[i], n) + v[i], solve(i + 1, j, n));
    }

    return res;
}

int main() {

    cout<<"hello world"<<endl;
    
    cin>>n;
    for (int i = 0; i < n; i ++) {
        cin>>w[i];
        cin>>v[i];
    }

    cin>>W;

    int res = solve(0, W, n);

    cout<<res;
}

