#include<iostream>

using namespace std;
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
out:
30
*/
const int N = 100;
int a[N][N];//输入数据
int d[N][N]; //表示到第N行,第N个元素的最大和,解释一下为啥得用两维数组表示
int row; //行数

void solve() {
    d[0][0] = a[0][0];//初始化一个初始状态
    for (int i = 1; i < row; i ++) {
        for (int j = 0; j < i + 1; j ++) {
            d[i][j] = max(d[i - 1][j - 1] + a[i][j], d[i - 1][j] + a[i][j]);
        }
    }
    for (int i = 0; i < row; i ++) {
        cout<<d[row - 1][i]<<" ";
    }
}

int main() {    

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            a[i][j] = -1;//初始化一下
            d[i][j] = 0;
        }
    }
    cin>>row;
    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < i + 1; j ++) {
            cin>>a[i][j];
        }
    }
    // for (int i = 0; i < row; i ++) {
    //     for (int j = 0; j < i + 1; j ++) {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    solve();

    return 0;
}