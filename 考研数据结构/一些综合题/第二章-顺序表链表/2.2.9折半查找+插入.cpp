#include<iostream>

using namespace std;

int n;
int a[100];
int key;

void solve() {

    int left = 0;
    int right = n - 1;
    int middle;

    while (left <= right) {
        middle = (left + right) / 2;
        if (a[middle] > key) {
            right = middle - 1;
        } else if (a[middle]<key) {
            left = middle + 1;
        } else {
            cout<<"hello"<<endl;
            swap(a[middle], a[middle + 1]);
            return ;
        }
    }

    //插入位置为 right + 1;
    for (int i = n; i > right + 1; i --) {
        a[i] = a[i - 1];
    }
    a[right + 1] = key;
    n = n + 1;
    return ;
}

int main() {

    cin>>n;
    cin>>key;
    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }

    solve();

    for (int i = 0; i < n; i ++) {
        cout<<a[i]<< " ";
    }

    // for (int j = 0; i < )
    return 0;
}