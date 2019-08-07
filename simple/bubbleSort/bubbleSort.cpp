#include<iostream>

using namespace std;

//冒泡排序

int main() {

    int n;//排序数字的个数
   
    int t;
    cout<<"hello world"<<endl;

    cin>>n;
    int a[n];//循环输入排序数字
    
    for (int l = 0; l < n; l ++) {
        cin>>a[l];
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n - 1; j ++) {
            if (a[j] > a[j + 1]) {
                //证明需要交换
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    for (int k = 0; k < n; k ++) {
        cout<<a[k]<<" ";
    }
    return 0;
}