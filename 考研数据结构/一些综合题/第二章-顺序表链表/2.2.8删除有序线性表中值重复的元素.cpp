#include<iostream>

using namespace std;

/* input 

5
1 2 2 3 4

*/  //此测试用例输出 1 2 3 4

int n;

struct List {
    int data[100];
    int length = 0;
};

void solve(List list) {

    int k = 0;
    
    for (int i = 1; i < list.length; i ++) {

        if (list.data[i] != list.data[k]) {
            k ++ ;
            list.data[k] = list.data[i];
        }
    }

    list.length = k + 1;
    

    for (int i = 0; i < list.length; i ++) {
        cout<<list.data[i]<<" ";
    }
}   

int main() {

    List list;
    cin>>n;
    list.length = n;
    for (int i = 0; i < n; i ++ ) {
        cin>>list.data[i];
    }

    solve(list);

    return 0;
}