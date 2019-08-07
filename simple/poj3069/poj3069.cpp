#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

#define maxn 1000

//N个点， R的范围内， X就是输入的N个点的坐标位置
int getAnswer(int N, int R, vector<int> X) {

    //先将每个点进行排序 从小到大
    sort(X.begin(), X.end());

    //从左边第一个点开始， 往右数R范围内 最靠近边界的一个点 进行标记 这样的话就可以肯定标记到最左边那个点了
    //再向右数R 找到出范围的第一个点  等同于左边第一个点！！
    int i = 0;
    int ans = 0;

    while(i < N) {

    int s = X[i];// s 是右侧没有被覆盖到的第一个点
    i += 1;
    while(X[i] <= s + R) {
            i += 1;
    }
    //上面循环完 找到的i 就是最靠近边界的一个点的后一个点
    int p = X[i - 1];//p就是标记的点
    ans += 1;

    //继续循环 向右走 又会找到右侧没有被覆盖到的第一个点 
    while(X[i] <= p + R) {
        i += 1;
    }
    //循环之后的i 又跟刚开始进入最外层循环的时候的那个i 一样了 ！！
    }
    
    return ans;

}

int main() {
    int R;
    int N;

    while(R != - 1 && N != -1) {
        cin>>R;
        cin>>N;
        if (R == -1 && N == -1) {
            return 0;
        }
        vector<int> v;
        int vv;
        for (int i = 0; i < N; i ++) {
            cin>>vv;
            v.push_back(vv);
        }
        cout<<getAnswer(N, R, v)<<endl;    
    
    }
    
    return 0;
}