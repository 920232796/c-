#include<bits/stdc++.h>


using namespace std;

int Father[100];


int find(int x, int flag) {
    if (flag == 1) {
        return Father[x];
    }
    cout<<"x: " <<x<<endl;
    cout<<"Father x: "<<Father[x]<<endl;
    if (x == Father[x]) {
        return x;
    }
    Father[x] = find(x, 1);
    return Father[x];
}

int main() {
    for (int i = 0; i < 10; i ++) {
    Father[i] = i;
    }

    Father[1] = 2;
    Father[3] = 2;
    cout<<"find: "<<find(1, 0);
    return 0;
}

