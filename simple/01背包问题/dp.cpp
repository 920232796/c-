#include<bits/stdc++.h>

using namespace std;

int dp[100][100];

int n;
int w[100];
int v[100];
int W;

int main()  {

    cout<<"hello world;"<<endl;
    memset(dp, 0, sizeof(dp));

    cin>>n;
    for (int i = 0; i < n; i ++) {
        cin>>w[i];
        cin>>v[i];
    }

    cin>>W;

    //i 一定从 1 开始 i = 0的时候 dp[0][j] 全是0
    for (int i = 1; i <= n; i ++) {

        for (int j = 1; j <= W; j ++) {

            if (j < w[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= W; j ++) {
            cout<<dp[i][j];
        }

        cout<<endl;
    }

    return 0;
}