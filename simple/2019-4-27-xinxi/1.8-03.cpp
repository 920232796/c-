#include<bits/stdc++.h>


using namespace std ;


int main() {

    int row = 3;
    int col = 3;

    int matrix[row][col];

    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < col; j ++) {
            int aa;
            cin>>aa;
            matrix[i][j] = aa;
        }
    }

    int res = 0;
    //1 
    res += matrix[0][0];
    res += matrix[0][col - 1];
    res += matrix[row - 1][0];
    res += matrix[row - 1][col - 1];
    for (int i = 1; i < col - 1; i ++) {
        res += matrix[0][i];
        res += matrix[row - 1][i];
        res += matrix[i][0];
        res += matrix[i][col - 1];
    }


    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < col; j ++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<res<<endl;

    return 0;
}