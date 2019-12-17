// 割绳子问题
#include<iostream>
#include<cmath>

using namespace std;

/*
4 11
8.02 7.43 4.57 5.39
out:
2.00
*/

int N; //一共几根绳子
int K;//一共切成几段
double L[10000];//绳子数组
//思路就是二分搜索，不断的假定解，然后带入看看能不能切
// int res[100];
bool CX(double x) {
    //判断如果割完后每段长度为x，能不能割K段
    int num = 0;
    for (int i = 0; i < N; i ++) {
        num += (int)(L[i] / x);
    }
    return num >= K; // num += K 说明可以，没问题
}

void solve() {
    double left = 0.0;
    double right = 100000.0;
    double middle;
    for (int i = 0; i < 100; i ++) {
        middle = (left + right) / 2;//不断缩小查找区间
        if (CX(middle)) {
            //说明middle可以，但是我们要找最大的那个middle,因此更新left
            left = middle;
        } else {
            //说明middle不可以，我们需要让middle减小一点！也就是更新right
            right = middle;
        }
    }
    //最后得到的middle肯定没问题了！
    // printf("%.2f\n", middle);
    printf("%.2f\n", (float)(floor(right * 100) / 100));
    // cout<<left<<endl;

}

int main() {
    cin>>N;
    cin>>K;
    for (int i = 0; i < N; i ++) {
        //输入每条绳子
        cin>>L[i];
    }
    solve();

    return 0;
}

