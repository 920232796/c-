#include<iostream>

using namespace std;

/* input
5
1 3 2 7 6
*/

#define MAX_N 1000

int n;
int a[MAX_N];

void bubble_sort() {

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n - i - 1; j ++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
   
}

int main() {
    cin>>n;

    for (int j = 0; j < n; j ++) {
        cin>>a[j];
    }

    bubble_sort();

    for (int i = 0; i < n; i ++) {
        cout<<a[i]<<" ";
    }
    return 0;
}