#include<bits/stdc++.h>

using namespace std;



int main() {
    int n;
    cin>>n;

    int a[n];
    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }

    int b[n - 1];
    for (int i = 0; i < n - 1; i ++) {
        b[i] = abs(a[i] - a[i + 1]);
    }

    sort(b, b + n - 1);

    int flag = 0;
    for (int i = 0; i < n - 1; i ++) {
        if (b[i] != i + 1) {
            cout<<"Not jolly";
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        cout<<"Jolly";
    }

    return 0;
}