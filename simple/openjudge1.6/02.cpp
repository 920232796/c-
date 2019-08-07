#include<iostream>
#include<string>

using namespace std;

int a[10];
int high;

int main() {
    for (int i = 0; i < 10; i ++) {
        //循环输入十个苹果的高度
        cin>>a[i];
    }
    cin>>high;//s输入身高
    int result = 0;

    for (int j = 0; j < 10; j ++) {
        if (high + 30 >= a[j]) {
            //证明够到
            result += 1;
        }
    }

    cout<<result<<endl;
    return 0;
}