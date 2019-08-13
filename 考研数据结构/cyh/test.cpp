#include<iostream>
using namespace std;

void solve(int answer, int n) {

    for (int i = 0; i < n; i ++) {
        answer = answer * 2;
    }
    cout<<answer<<endl;
}

int main(){
    int answer = 1;
    int n;
    
    cin>>n;

    solve(answer, n);

    return 0;
}