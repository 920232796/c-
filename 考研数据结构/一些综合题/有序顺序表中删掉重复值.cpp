#include<iostream>

using namespace std; 

int n;
int a[100];

void solve() {

    if (n == 0) {
        return ;
    }
    int i, j;
    i = 0;
    for (j = 0; j < n; j ++) {
        if (a[i] != a[j]) {
            i ++;
            a[i] = a[j];
        }
    }
    n = n - i;
}

int main() {

    cin>>n;
    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }

    solve();

  for (int i = 0; i < n; i ++) {
        cout<<a[i]<<" ";
    }

    return 0;
}