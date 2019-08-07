#include<iostream>

using namespace std;

#define MAX_N 1000

int n;
int a[MAX_N];

void insert_order() {
    int i = 0;
    for (int j = 1; j < n; j ++) {
        for (int k = j - 1; k >= 0; k ++) {

            if (a[j] < a[k]) {
                swap(a[j], a[k]);
                break;
            }
        }
    }
}

int main() {
    cin>>n;
    for (int j = 0; j < n; j ++) {
        cin>>a[j];
    }
    insert_order();
    for (int i = 0; i < n; i ++) {
        cout<<a[i]<<" ";
    }
    return 0;
}