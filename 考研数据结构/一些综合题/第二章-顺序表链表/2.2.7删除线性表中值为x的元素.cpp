#include<iostream>

using namespace std;

/* input 

5
3
2 3 4 3 2

*/  //此测试用例输出 2 4 2 删掉了 元素 3

int n;

struct List {
    int data[100];
    int length = 0;
};

void solve(List list, int x) {
    int k = 0; //表示当前线性表的长度 如果遇到 等于x 的元素 k的值不动，这样就把x元素给排除出去了

    for (int i = 0; i < n; i ++) {
        if (list.data[i] != x) {
            list.data[k] = list.data[i];
            k ++;
        }
    }

    list.length = k;

    for (int j = 0; j < list.length; j ++) {
        cout<<list.data[j]<<" ";
    }
}   

int main() {

    List list;
    cin>>n;
    list.length = n;
    int x;
    cin>>x;
    for (int i = 0; i < n; i ++ ) {
        cin>>list.data[i];
    }

    solve(list, x);

    return 0;
}