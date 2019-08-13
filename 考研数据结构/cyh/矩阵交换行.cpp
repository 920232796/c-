#include<iostream>

using namespace std;

int a[5][5];

int row_1;
int row_2;

int main() {

    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j ++) {
            cin>>a[i][j];
        }
    }

    cin>>row_1;
    cin>>row_2;


    for (int i = 0; i < 5; i++) {
        int temp = a[row_1 - 1][i];
        a[row_1 - 1][i] = a[row_2 - 1][i];
        a[row_2 - 1][i] = temp;
    }

    
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j ++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}