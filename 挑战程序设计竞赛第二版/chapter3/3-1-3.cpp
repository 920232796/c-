#include<iostream>
#include<algorithm>

using namespace std;
//poj 2456 把牛放入牛舍，使得牛的距离尽量远
/*
input:
5 3
1 2 8 4 9
out:
3
*/

int N;//牛的个数
int M; //牛舍个数
int X[110000]; //牛舍距离

bool C(int i) {
    //判断任意两头牛之间的距离是否可以都大于i
    int num = 0;
    int pos = -100000000; //为了放第一头牛，初始化一个很远的距离
    for (int j = 0; j < M; j ++) {
        if (X[j] - pos >= i) {
            //说明把牛放入j所对应的位置没问题！
            num ++;
            pos = X[j];//更新pos
            if (num == N) {
                //证明牛都放完了
                return true;
            }
        }
    }
    return false; //说明不行 牛还放不完！
}

void solve() {
    int left = 0;
    int right = 1000000001;
    int middle;
    while (right - left > 1) {
        middle = (left + right) / 2;
        if (C(middle)) {
            //说明可以当前middle的距离可以放完所有牛，因此需要扩大一下middle试试
            left = middle;
        } else {
            right = middle;
        }
    }
    cout<<left<<endl;
    // cout<<right<<endl;
    // cout<<middle<<endl;
}

int main() {
    cin>>M;
    cin>>N;
    for (int i = 0; i < M; i ++) {
        cin>>X[i];
    }
    sort(X, X + M);
    solve();
    return 0;
}