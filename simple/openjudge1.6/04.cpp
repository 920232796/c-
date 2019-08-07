#include<iostream>

using namespace std;

int N;

int main() {
    cin>>N;
    int a[N];

    for (int i = 0; i < N; i ++) {
        cin>>a[i];
    }

    for (int k = 0; k < N; k ++) {
        cout<<a[N - k - 1]<<" ";
    }
    return 0;
}