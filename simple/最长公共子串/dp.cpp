#include<bits/stdc++.h>

using namespace std;


int getAnswer(int n, int m, string s, string t) {

    //初始化dp[i][j]
    int dp[n + 1][m + 1];

    memset(dp, 0, sizeof(dp));
    
    string result;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            
            if (s.substr(i, 1) == t.substr(j, 1)) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                result.append(s.substr(i, 1));
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    cout<<dp[n][m]<<"("<<result<<")";

    return 0;
}

int main() {
    getAnswer(4, 4, "abcd", "becd");
    return 0;
}