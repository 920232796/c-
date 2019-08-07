#include<iostream>

using namespace std;

#define MAX_N 1000
///插入位置为 right + 1     ！！！  记住


int n;
int a[MAX_N];

void mean_insert_order() {

    for (int i = 1; i < n; i ++) {// i = 1表示 前面1个元素已经排好序
        
        int left = 0;
        int right = i - 1;
        int middle = 0;
        while (left <= right) {
            middle = (left + right) / 2;
            if (a[middle] < a[i]) {
                left = middle + 1;
            } else if (a[middle] > a[i]) {
                right = middle - 1;
            } else {
                right = middle;
                break;
            }
        }

        //找到插入位置了 right + 1 其余后移
        int tar = a[i]; 
        for (int j = i; j >= right + 2; j --) {
            a[j] = a[j - 1];
        }
        a[right + 1] = tar;
    }
   
}

int main() {
    cin>>n;
    for (int j = 0; j < n; j ++) {
        cin>>a[j];
    }
    mean_insert_order();
    for (int i = 0; i < n; i ++) {
        cout<<a[i]<<" ";
    }
    return 0;
}