#include<iostream>

using namespace std;

/* input
5
1 3 2 7 6
*/

#define MAX_N 1000

int n;
int a[MAX_N];

void shell_order() {
    int dk;

    for (int dk = n / 2; dk >= 1; dk /= 2) {
        int i, j;
        for (i = dk; i < n; i ++) {
            // 先找到这个待插入的数字 因为默认 第一个数字为有序 因此i = dk
            if (a[i] >= a[i - dk]) {
                // 不需要插入排序了
                continue;
            }

            for (j = i - dk; j >= 0; j -= dk) {
                if (a[j] > a[i]) {
                    swap(a[j], a[i]);
                } else {
                    break;
                }
            }
        }
    }
   
}

int main() {
    cin>>n;

    for (int j = 0; j < n; j ++) {
        cin>>a[j];
    }

    shell_order();

    for (int i = 0; i < n; i ++) {
        cout<<a[i]<<" ";
    }
    return 0;
}