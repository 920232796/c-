#include<iostream>

using namespace std;

int solve(int n) {
    if (n == 1) {
        return 1;
    }

    return n * solve(n - 1);
}

int main() {

    int r = solve(5);

    cout<<r<<endl;

    return 0;
}