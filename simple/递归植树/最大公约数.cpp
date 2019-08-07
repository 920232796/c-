#include<iostream>

using namespace std;

int fas(int a, int b) {
    int r = a % b;

    if (r == 0) {
        return b;
    }
    
    a = b;
    b = r;
    return fas(a, b);
}

int main() {

    int i;
    int j;
    cin>>i>>j;
    cout<<fas(i, j)<<endl;
    return 0;
}