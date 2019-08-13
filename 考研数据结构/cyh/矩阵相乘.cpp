#include<iostream>

using namespace std;

int m;
int k;
int n;

int a[100][100];
int b[100][100];
int c[100][100];

void solve() {

    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            c[i][j] = 0;
            for (int l = 0; l < k; l ++) {
                c[i][j] = c[i][j] + a[i][l] * b[l][j];
            }
        }
    }
}

int main() {

    cin>>m;
    cin>>k;
    cin>>n;

    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < k; j ++) {
            cin>>a[i][j];
        }
    }
    
    for (int i = 0; i < k; i ++) {
        for (int j = 0; j < n; j ++) {
            cin>>b[i][j];
        }
    }

    cout<<endl;



    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < k; j ++) {
        cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for (int i = 0; i < k; i ++) {
        for (int j = 0; j < n; j ++) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    solve();


     for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}