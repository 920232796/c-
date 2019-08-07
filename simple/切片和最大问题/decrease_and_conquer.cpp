#include<bits/stdc++.h>

//减而治之 的方法 把复杂度减小为 O（n） ！！ 不断的从末尾进行查 如果序列和小于等于0 那么就剪掉！ 不断的减！

using namespace std;

//n为序列里面数字个数  slice 为序列
int getMaxLen(int n, vector<int> slice) {

    int s = 0; 
    int i = n;
    int gLength = 0;

    while (i > 0) {

        s = slice[i - 1] + s;
        if (s > gLength) {
            //证明找到了一个最大的
            gLength = s;
        }
        if (s <= 0) {
            //剪掉
            s = 0;
        }
        i = i - 1;
    }

    return gLength; 
}

int main() {

    int n;
    cin>>n;
    vector<int> slice;

    for (int i = 0; i < n; i ++) {
        int d;
        cin>>d;
        slice.push_back(d);
    }

    cout<<getMaxLen(n, slice)<<endl;

    return 0;
}