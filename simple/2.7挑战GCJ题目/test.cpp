#include<bits/stdc++.h>

using namespace std;

int main() {

    int v1[5];
    for (int i = 0; i < 5; i ++) {
        int a;
        cin>>a;
        v1[i] = a;
    }

    sort(v1, v1 + 5);

    for (int j = 0; j < 5; j ++) {
        cout<<v1[j]<<endl;
    }
    return 0;
}