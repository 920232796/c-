#include<iostream>
#include<algorithm>

using namespace std;

int fun(int n) {
    int z;
    if (n > 2) {
        z = fun(n - 1) + fun(n - 2);
    }
    else if (n == 0 | n == -1) {
        z = 0;
    }
    else {
        z = 1;
    }
    return z;
}

int main() {

    int n = 0;
    while(n != -1){
        cin>>n;
        int result = fun(n);
        cout<<result<<endl;
    }
    
    return 0;
}