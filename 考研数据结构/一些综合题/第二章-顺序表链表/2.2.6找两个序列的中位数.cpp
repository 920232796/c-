#include<iostream>

//注意是等长序列。 有序
using namespace std;

/*  input 

5
11 13 15 17 19
2 4 6 8 20


*/  // 此测试用例输出为 11

int n;
int a[100];
int b[100];

void solve() {
    int a_point = 0;
    int b_point = 0;
    int c = 0;//计数器 计数到 n/2 的位置 便找到了中位数
    while (a_point < n && b_point < n) {
        if (a[a_point] <= b[b_point]) {
            c ++;

            if (c == n) {
            cout<<a[a_point]<<endl;
            }   

            a_point ++;
        } else {
            c++;

            if (c == n) {
            cout<<b[b_point]<<endl;
            } 

            b_point ++;
        }
    }
}


int main() {

    cin>>n;
    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }

    for (int i = 0; i < n; i ++) {
        cin>>b[i];
    }

    solve();

    return 0;
}