#include<bits/stdc++.h>

using namespace std;


int mathTriangle(vector<vector<int>> matrix) {

    int dp[matrix.size()][matrix.size()];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 0; i < matrix.size(); i ++) {
        for (int j = 0; j < matrix.size(); j ++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i = 1; i < matrix.size(); i ++) {
        for (int j = 0; j < i + 1; j ++) {
            if (j == 0) {
                dp[i][j] = max(dp[i-1][j] + matrix[i][j], dp[i - 1][j + 1] + matrix[i][j]);
            } else {
                dp[i][j] = max(dp[i - 1][j] + matrix[i][j], max(dp[i - 1][j - 1] + matrix[i][j], dp[i - 1][j + 1] + matrix[i][j]));
            }
        }
    }

    for (int i = 0; i < matrix.size(); i ++) {
        for (int j = 0; j < i + 1; j ++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    int maxDigit = 0;
    for (int k = 0; k < matrix[matrix.size() - 1].size(); k ++) {
        maxDigit = max(maxDigit, dp[matrix.size() - 1][k]);
    } 

    return maxDigit;
}

int main() {

    cout<<"hello world";
    vector<vector<int>> matrix = {
        {1, 0, 0, 0, 0}, 
        {2, 3, 0, 0, 0},
        {2, 2, 1, 0, 0}, 
        {5, 3, 1, 3, 0},
        {1, 3, 2, 5, 1}
    };
    int res = mathTriangle(matrix);
    cout<<"Res: "<<res<<endl;
    return 0;
}