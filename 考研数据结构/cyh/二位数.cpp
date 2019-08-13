#include<iostream>
using namespace std;

int n;
int a[100];

void solve() {
    int max_number = -10000;

    for (int i = 0; i < n; i ++) {
        if (a[i] > max_number) {
            max_number = a[i];0000000000000000000000000000000000000000
        }
    }

    cout<<max_number<<endl;
    
}

int main(){
   
    
    cin>>n;

    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }

    solve();

    return 0;
}