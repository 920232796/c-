#include<iostream>
#include<algorithm>

using namespace std;
//硬币问题，贪心算法
int v[6] = {1, 5, 10, 50, 100, 500};

int c[6]; //每个面值多少张

int A;//支付A元

int n[6];//张数

int main() {
    for (int j = 0; j < 6; j ++) {
        cin>>c[j];
    }
    cin>>A;
    for (int i = 5; i >= 0; -- i) {
        n[i] = min((int)(A / v[i]), c[i]);
        A = A - n[i] * v[i];      
    }
    for (int i = 0; i < 6; i ++) {
        cout<<n[i]<<endl;
    }
    return 0;
}