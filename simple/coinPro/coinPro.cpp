#include<iostream>
#include<algorithm>

using namespace std;
//Ӳ�����⣬̰���㷨
int v[6] = {1, 5, 10, 50, 100, 500};

int c[6]; //ÿ����ֵ������

int A;//֧��AԪ

int n[6];//����

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