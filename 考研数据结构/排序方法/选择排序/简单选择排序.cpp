#include<iostream>

using namespace std;

/* input
5
1 3 2 7 6
*/

#define MAX_N 1000

int n;
int a[MAX_N];

void select_sort() {

    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (a[j] < a[i]) {
                swap(a[j], a[i]);
            }
        }
    }
}

int main() {
    cin>>n;

    for (int j = 0; j < n; j ++) {
        cin>>a[j];
    }

    select_sort();

    for (int i = 0; i < n; i ++) {
        cout<<a[i]<<" ";
    }
    return 0;
}