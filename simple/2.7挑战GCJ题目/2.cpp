#include<bits/stdc++.h>

using namespace std; 

#define MAX_N 10000

int N; //行数
int m[MAX_N][MAX_N];
int position[MAX_N];//记录每一行最后一个1 的位置

int solve() {

    int res = 0;
    for (int i = 0; i < N - 1; i ++) {

        for (int j = i; j < N; j ++) {
            if (position[j] == i) {
                //证明找到需要放到第i行的那一行了！ 看看需要几次交换能换过来
                //看这个j就行 比如现在要找第0行，结果一看 第0行其实现在在第3行，所以就第三行先跟第二行换一次，
                // 第二行再跟第一行换一次，第一行再跟第0行换一次，一共换了三次！
                for (int k = i + 1; k <= j - i; k ++) {
                    swap(position[k], position[k - 1]);
                }
                res += j - i; //j - i 是需要交换多少次
            }
        }
    }

    return res;
}

int main() {

    cin>>N;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            int a;
            cin>>a;
            if (a == 1) {
                position[i] = j;
            }
            m[i][j] = a;
        }
    }

    int res = solve();
    cout<<res<<endl;
    return 0;
}