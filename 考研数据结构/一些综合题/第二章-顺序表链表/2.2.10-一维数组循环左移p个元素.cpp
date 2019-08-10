#include<iostream>
// 三次reverse 反转数组 ~
using namespace std;

int n;
int a[100];
int p;

void reverse(int a[], int from, int to) {
    while (from <= to) {
        swap(a[from], a[to]);
        from ++;
        to --;
    }
}

void solve() {
    reverse(a, 0, p - 1);
    reverse(a, p, n - 1);
    reverse(a, 0, n - 1);
}

int main() {

    cin>>n;
    cin>>p;

    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }

    solve();

    for (int i = 0; i < n; i ++) {
        cout<<a[i]<< " ";
    }

    return 0;
}