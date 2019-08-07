#include<iostream>

/*
5 8
1 2 3 4 5 6 7 8
 */

using namespace std;

int a[1000];
int n;
int key;

int main() {

    cin>>key;
    cin>>n;
    for (int i = 0; i < n; i ++) {
        cin>>a[i];
    }

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (a[middle] < key) {
            left = middle + 1;
        } else if (a[middle] > key) {
            right = middle - 1;
        } else {
            cout<<"res = "<<middle<<endl;
            return 0;
        }
    }
    cout<<"res = "<<-1<<endl;
    return 0;
}