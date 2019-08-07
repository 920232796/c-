#include<iostream>
#include<algorithm>

/*
    intput   4 16
    output   3 1 2 4
*/
using namespace std;

#define MAX_N 11

int N;

int a[MAX_N];

int sum;

// 判断函数，判断是此排列的最终结果为 sum 
bool judge() {

    int b[MAX_N];
    //为了不影响a数组 弄一个b数组临时用
    for (int j = 0; j < N; j ++) {
        b[j] = a[j];
        // cout<<b[j]<<endl;
    }

    // 判断的关键代码
    for (int i = 0; i < N - 1; i ++) {
        for (int j = 0; j  < N - 1 - i; j ++) {
            b[j] = b[j] + b[j + 1];
        }
    }

    if (b[0] == sum) {
        return true;
    } else {
        return false;
    }
}

void solve() {

    do {
        if (judge()) {
            for (int i = 0; i < N; i ++) {
                cout<<a[i]<<" ";
            }
            return;
        }
    } while(next_permutation(a, a + N)); //得到所有全排列
}

int main() {

    cin>>N;
    cin>>sum;
    if (N == 1) {
        if (sum != 1) {
            cout<<-1<<endl;
            return 0;
        } else {
            cout<<1<<endl;
            return 0;
        }
    }
    for (int i = 0; i < N; i ++) {
        a[i] = i + 1;
    }

    solve();

    return 0;
}