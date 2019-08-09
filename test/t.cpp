#include<bits/stdc++.h>

using namespace std;

int main() {
    int a[5] = {6, 2, 3, 4, 5};
    sort(a, a + 5);

    for (int i = 0; i < 5; i ++) {
        cout<<a[i]<<" ";
    }
}