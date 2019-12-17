//从有序数组中查找某个值
#include<iostream>

using namespace std;
/*
input: 
5
2 3 3 5 6
3
output:
1
*/
int N; //数组中元素个数
int a[10000];
int k; //需要查找的那个数字

void solve() {
    int left = 0;
    int right = N;
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (a[middle] == k) {
            //找到了,但是不一定middle最小，继续往前看
            while (a[middle] == a[middle - 1]) {
                middle -= 1;
            }
            cout<<middle<<endl;
            return;
        }
        if (a[middle] < k) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
}

int main() {

    cin>>N;
    for (int i = 0;i < N; i ++) {
        cin>>a[i];
    }
    cin>>k;
    solve();
    return 0;
}