#include<iostream>

using namespace std;

int n = 6;

int m = 0;


int main() {

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= 2 * i; j ++) {
            m ++;
        }
    }    

    cout<<m<<endl;
    return 0;
}