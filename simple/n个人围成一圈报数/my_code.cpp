#include<iostream>

using namespace std;

int N;
int m;
int p[1001] = {0};

int main() {

    cin>>N;
    cin>>m;
    for (int i = 0; i < N; i ++) {
        p[i] = 1;// 1 表示在圈里面
    }

    int s = 0; //出圈人数
    // int s1 = 0;//计数器
    int s2 = 0;

    while (s < N) {
        //出圈条件
        for (int j = 0; j < N; j ++) {
            if (p[j] == 1) {
                //z证明在圈里面 需要报数
                s2 += 1;
                if (s2 == m) {
                    //证明报到m了 chu出圈
                    p[j] = 0;
                    cout<<j+1<<" ";
                    s2 = 0;
                    s += 1;
                }
            }
        }
    }

    return 0;
}