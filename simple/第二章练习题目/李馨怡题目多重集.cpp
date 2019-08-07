#include<iostream>
#include<algorithm>

using namespace std;

#define N 100000

int n;
int A[N];
int B[N];

void solve() {

    int temp_A[n];
    int temp_B[n];

    for (int i = 0; i < n; i ++) {
        temp_A[i] = A[i];
        temp_B[i] = B[i];
    }
    
    sort(temp_A, temp_A + n);
    sort(temp_B, temp_B + n);

    int flag_a = 0;
    int flag_b = 0; //两个指针 从A B的最左侧开始

    int sum_a = 0;
    int sum_b = 0;

    int flag = 0; // flag = 1的话 就是要更新sum_a 如果 flag=2 就是更新 sum_b 等于0只有刚开始是等于0 因为刚开始sum_a sum_b都要加第一次
    while (flag_a < n && flag_b < n) {

        if (flag == 0) {
            sum_a = sum_a + temp_A[flag_a];
            sum_b = sum_b + temp_B[flag_b];
        } else if (flag == 1) {
            sum_a = sum_a + temp_A[flag_a];
        } else {
            sum_b = sum_b + temp_B[flag_b];
        }
      
        if (sum_a == sum_b) {
            //找到结果 结束
            cout<<flag_a + 1<<endl;
            for (int i = 0; i < flag_a + 1; i ++) {
                for (int j = 0; j < n; j ++) {
                    if (A[j] == temp_A[i]) {
                        cout<<j<<" ";
                        A[j] = -1000000;
                        break;
                    }
                }
            }
            cout<<endl;

            cout<<flag_b + 1<<endl;
            for (int i = 0; i < flag_b + 1; i ++) {
                for (int j = 0; j < n; j ++) {
                    if (B[j] == temp_B[i]) {
                        cout<<j<<" ";
                        B[j] = -1000000;
                        break;
                    }
                }
            } 
            cout<<endl;

            return ;
        }

        if (sum_a > sum_b) {
            flag_b ++;
            flag = 2;
        }

        if (sum_a < sum_b) {
            flag_a ++;
            flag = 1;
        }

    }
    cout<<-1<<endl;
    return ;
}

int main() {
    cin>>n;

    for (int i = 0; i < n; i ++) {
        cin>>A[i];
    }
    for (int j = 0; j < n; j ++) {
        cin>>B[j];
    }

    solve();

    return 0;
}