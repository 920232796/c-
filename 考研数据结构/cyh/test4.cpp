#include<iostream>

using namespace std;

int main() {

    int G[5][5] = {1};

    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j ++) {
            cout<<G[i][j]<<endl;
        }
    }
    return 0;
}